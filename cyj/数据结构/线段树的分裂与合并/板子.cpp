#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 6e5 + 10;
int n, m;;
struct node {
    int l, r;
    ll num;
}tr[N * 4];
int root[N], tt, nodes[N * 4], w[100020], r_cnt = 1;

int New(){
    return nodes[tt --];
}

void Del(int &now){
    tr[now].l = tr[now].r = tr[now].num = 0;
    nodes[++ tt] = now;
    now = 0;
}

void pushup(int u){
    tr[u].num = tr[tr[u].l].num + tr[tr[u].r].num;
}

int build(int l, int r){
    int q = New();
    if (l == r){
        tr[q].num = w[l];
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
    if (y >= mid) Split(tr[p].r, tr[q].r, x, y, mid + 1, r);
    pushup(p), pushup(q);
}

void Merge(int &p, int &q, int l, int r){
    if (!p || !q){
        p += q;
        return;
    }
    if (l == r){
        tr[p].num += tr[q].num;
        Del(q);
        return;
    }
    int mid = l + r >> 1;
    Merge(tr[p].l, tr[q].l, l, mid), Merge(tr[p].r, tr[q].r, mid + 1, r);
    Del(q);
    pushup(p);
}

void update(int &u, int pos, int x, int l, int r){
    if (!u) u = New();
    if (l == r){
        tr[u].num += x;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(tr[u].l, pos, x, l, mid);
    else update(tr[u].r, pos, x, mid + 1, r);
    pushup(u);
}

ll query(int u, int x, int y, int l, int r){
    if (!u) return 0;
    if (l >= x && r <= y) return tr[u].num;
    int mid = l + r >> 1;
    ll res = 0;
    if (x <= mid) res += query(tr[u].l, x, y, l, mid);
    if (y > mid) res += query(tr[u].r, x, y, mid + 1, r);
    return res;
}

int get_k(int u, int k, int l, int r){
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tr[tr[u].l].num >= k) return get_k(tr[u].l, k, l, mid);
    else return get_k(tr[u].r, k - tr[tr[u].l].num, mid + 1, r);
}

int main(){
    for (int i = 1; i < N * 4; i ++) nodes[++ tt] = i;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    root[1] = build(1, n);
    while (m --){
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        if (!a){
            scanf("%d%d", &x, &y);
            Split(root[b], root[++ r_cnt], x, y, 1, n);
        }
        else if (a == 1){
            scanf("%d", &x);
            Merge(root[b], root[x], 1, n);
            Del(root[x]);
        }
        else if (a == 2){
            scanf("%d%d", &x, &y);
            update(root[b], y, x, 1, n);
        }
        else if (a == 3){
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(root[b], x, y, 1, n));
        }
        else {
            scanf("%d", &x);
            if (tr[root[b]].num < x) puts("-1");
            else {
                printf("%d\n", get_k(root[b], x, 1, n));
            }
        }
    }
    return 0;
}