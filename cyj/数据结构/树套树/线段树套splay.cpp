/*
 * @Descripttion: 
 1 l r x，查询整数 x 在区间 [l,r] 内的排名。
 2 l r k，查询区间 [l,r] 内排名为 k 的值。
 3 pos x，将 pos 位置的数修改为 x。
 4 l r x，查询整数 x 在区间 [l,r] 内的前驱(前驱定义为小于 x，且最大的数)。
 5 l r x，查询整数 x 在区间 [l,r] 内的后继(后继定义为大于 x，且最小的数)。
 * @Topic link: https://www.acwing.com/problem/content/2478/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-26 14:18:54
 * @LastEditTime: 2021-08-19 22:00:45
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 1500005, INF = 1e9;
typedef long long LL;

struct node {
    int s[2], p, v;
    int size;
    void init(int v1, int p1){
        v = v1, p = p1, size = 1;
    }
}tr[N];
int L[N], R[N], w[N], T[N], idx;
int n, m;

void pushup(int u){
    tr[u].size = tr[tr[u].s[0]].size + tr[tr[u].s[1]].size + 1;
}

void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k^1], tr[tr[x].s[k^1]].p = y;
    tr[x].s[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int &root, int x, int k){
    while (tr[x].p != k){
        int y =  tr[x].p, z = tr[y].p;
        if (z != k){
            if (tr[z].s[1] == y ^ tr[y].s[1] == x) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root = x;
}

void insert(int &root, int v){
    int u = root, p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++ idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(root, u, 0);
}

void update(int &root, int x, int y){
    int u = root;
    while (u){
        if (tr[u].v == x) break;
        if (tr[u].v < x) u = tr[u].s[1]; 
        else u = tr[u].s[0]; 
    }
    splay(root, u, 0);
    int l = tr[u].s[0], r = tr[u].s[1];
    while (tr[l].s[1]) l = tr[l].s[1];
    while (tr[r].s[0]) r = tr[r].s[0];
    
    splay(root, l, 0), splay(root, r, l);
    tr[r].s[0] = 0;
    pushup(r), pushup(l); // 注意
    insert(root, y);
}

int get_pre(int root, int x){
    int u = root, res = -INF;
    while (u){
        if (tr[u].v < x) res = max(res, tr[u].v), u = tr[u].s[1];
        else u = tr[u].s[0]; 
    }
    return res;
}

int get_suc(int root, int x){
    int u = root, res = INF;
    while (u){
        if (tr[u].v > x) res = min(res, tr[u].v), u = tr[u].s[0];
        else u = tr[u].s[1];
    }
    return res;
}

void build(int u, int l, int r){
    L[u] = l, R[u] = r;
    insert(T[u], -INF), insert(T[u], INF);
    for (int i = l; i <= r; i ++) insert(T[u], w[i]);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
}

// void dfs(int u){
//     if (tr[u].s[0]) dfs(tr[u].s[0]);
//     if (tr[u].s[1]) dfs(tr[u].s[1]);
//     cout << tr[u].v << ' ';
// }

int get_k(int root, int k){
    int u = root, res = 0;
    while (u){
        if (tr[u].v < k) res += tr[tr[u].s[0]].size + 1, u = tr[u].s[1];
        else u = tr[u].s[0];
    }
    return res;
}

int query(int u, int l, int r, int x){
    if (L[u] >= l && R[u] <= r) return get_k(T[u], x) - 1;
    int mid = L[u] + R[u] >> 1, res = 0;
    if (l <= mid) res += query(u<<1, l, r, x);
    if (r > mid) res += query(u<<1|1, l, r, x);
    return res;
}

void change(int u, int pos, int x){
    update(T[u], w[pos], x);
    if (L[u] == R[u]) return;
    int mid = L[u] + R[u] >> 1;
    if (pos <= mid) change(u<<1, pos, x);
    else change(u<<1|1, pos, x);
}

int query_pre(int u, int l, int r, int x){
    if (L[u] >= l && R[u] <= r) return get_pre(T[u], x);
    int mid = L[u] + R[u] >> 1, res = -INF;
    if (l <= mid) res = max(res, query_pre(u<<1, l, r, x));
    if (r > mid) res = max(res, query_pre(u<<1|1, l, r, x));
    return res;
}

int query_suc(int u, int l, int r, int x){
    if (L[u] >= l && R[u] <= r) return get_suc(T[u], x);
    int mid = L[u] + R[u] >> 1, res = INF;
    if (l <= mid) res = min(res, query_suc(u<<1, l, r, x));
    if (r > mid) res = min(res, query_suc(u<<1|1, l, r, x));
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    build(1, 1, n);
    while (m --){
        int op;
        scanf("%d", &op);
        if (op == 1){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", query(1, l, r, k) + 1); // 求出小于k的数量，所以k的排名为答案 + 1
        }
        else if (op == 2){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            int a = 0, b = 1e8;  
            /** 求区间l到r中排名为k的数，由于知道左右区间排名为k的数并不能求出总区间排名为k的数，
             * 二分值域，判断mid是否为排名为k的数
             */
            while (a < b){
                int mid = a + b  + 1 >> 1;
                if (query(1, l, r, mid) + 1 <= k) a = mid;
                else b = mid - 1; 
            }
            printf("%d\n", a);
        }
        else if (op == 3){
            int pos, k;
            scanf("%d%d", &pos, &k);
            
            change(1, pos, k);
            w[pos] = k;
        }
        else if (op == 4){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", query_pre(1, l, r, k));
        }
        else {
            int l, r , k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", query_suc(1, l, r, k));
        }
    }
    return 0;
}
