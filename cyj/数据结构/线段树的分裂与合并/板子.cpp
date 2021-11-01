/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P5494
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-18 19:24:54
 * @LastEditTime: 2021-08-18 20:51:40
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = N * 4 + N * 20;
struct node {
    int l, r;
    ll sum;
}tr[M];
int nodes[M], tt, root[M], r_cnt = 1;
int n, m, w[N];

int New(){
    return nodes[tt --];
}

void Del(int &now){
    tr[now].l = tr[now].r = tr[now].sum = 0;
    nodes[++ tt] = now;
    now = 0;
}

void pushup(int u){
    tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
}

int build(int l, int r){
    int q = New();
    if (l == r){
        tr[q].sum = w[l];
        return q;
    }
    int mid = l + r >> 1;
    tr[q].l = build(l, mid), tr[q].r = build(mid + 1, r);
    pushup(q);
    return q;
}

void Split(int &p, int &q, int x, int y, int l, int r){
    if (!p) return;
    if (l >= x && r <= y){
        q = p;
        p = 0;
        return;
    }
    if (!q) q = New();
    int mid = l + r >> 1;
    if (x <= mid) Split(tr[p].l, tr[q].l, x, y, l, mid);
    if (y > mid)Split(tr[p].r, tr[q].r, x, y, mid + 1, r);
    pushup(p);
    pushup(q);
}

void Merge(int &p, int &q, int l, int r){
    if (!p || !q){
        p += q;
        return;
    }
    if (l == r){
        tr[p].sum += tr[q].sum;
        Del(q);
        return;
    }
    int mid = l + r >> 1;
    Merge(tr[p].l, tr[q].l, l, mid), Merge(tr[p].r, tr[q].r, mid + 1, r);
    Del(q);
    pushup(p);
}

ll query(int &u, int x, int y, int l, int r){
    if (!u) return 0;
    if (l >= x && r <= y){
        return tr[u].sum;
    }
    int mid = l + r >> 1;
    ll res = 0;
    if (x <= mid) res += query(tr[u].l, x, y, l, mid);
    if (y > mid) res += query(tr[u].r, x, y, mid + 1, r);
    return res;
}

void update(int &u, int pos, int x, int l, int r){
    if (!u) u = New();
    if (l == r){
        tr[u].sum += x;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(tr[u].l, pos, x, l, mid);
    if (pos > mid) update(tr[u].r, pos, x, mid + 1, r);
    pushup(u);
}

int get_k(int &u, ll k, int l, int r){
    if (!u || k > tr[u].sum) return -1;
    if (l == r) return l;
    int mid = l + r >> 1;
    ll t = tr[tr[u].l].sum;
    if (t >= k) return get_k(tr[u].l, k, l, mid);
    else return get_k(tr[u].r, k - t, mid + 1, r);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i < M; i ++) nodes[++ tt] = i;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    root[1] = build(1, n);
    for (int i = 0; i < m; i ++){
        int op, p, x, y, q, t;
        ll k;
        scanf("%d", &op);
        if (!op){
            scanf("%d%d%d", &p, &x, &y);
            Split(root[p], root[++ r_cnt], x, y, 1, n);
        }
        else if (op == 1){
            scanf("%d%d", &p, &t);
            Merge(root[p], root[t], 1, n); // Merge过程中已经把root[t]树删完了，之后再删会引起错误， 点被再次回收
        }
        else if (op == 2){
            scanf("%d%d%d", &p, &x, &q);
            update(root[p], q, x, 1, n);
        }
        else if (op == 3){
            scanf("%d%d%d",&p, &x, &y);
            printf("%lld\n", query(root[p], x, y, 1, n));
        }
        else if (op == 4){
            scanf("%d%lld", &p, &k);
            printf("%d\n", get_k(root[p], k, 1, n));
        }
    }
    return 0;
}