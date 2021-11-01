/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P2617
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-24 20:23:21
 * @LastEditTime: 2021-08-24 20:23:50
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

// 由于外层是权值线段树，
const int N = 1e5 + 10, P = N * 20 * 20, M = N * 8;
int tt;
struct node {
    int l, r;
    int num;
}tr[P];
vector<int> nums;
int n, m, w[N];
int L[M], R[M], T[M];

struct query{
    int o, l, r, x;
}q[N];

int New(){
    return ++ tt;
}

int find(int x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

void build(int u, int l, int r){
    L[u] = l, R[u] = r, T[u] = New();
    if (l == r) return;
    int mid = l + r >> 1;
    build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
}

void pushup(int u){
    tr[u].num = tr[tr[u].l].num + tr[tr[u].r].num;
}

void update(int &u, int l, int r, int pos, int v){
    if (!u) u = New();
    if (l == r){
        tr[u].num += v;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(tr[u].l, l, mid, pos, v);
    else update(tr[u].r, mid + 1, r, pos, v);
    pushup(u);
}

void change(int u, int x, int pos, int v){
    update(T[u], 1, n, pos, v);
    if (L[u] == R[u]) return;
    int mid = L[u] + R[u] >> 1;
    if (x <= mid) change(u<<1, x, pos, v);
    else change(u<<1|1, x, pos, v);
}

int get(int u, int a, int b, int l, int r){
    if (l >= a && r <= b){
        return tr[u].num;
    }
    int mid = l + r >> 1;
    int res  =0;
    if (a <= mid) res += get(tr[u].l, a, b, l, mid);
    if (b > mid) res += get(tr[u].r, a, b, mid + 1, r);
    return res;
}

int query(int u, int l, int r, int k){
    int t = get(T[u<<1], l, r, 1, n);
    if (L[u] == R[u]) return L[u];
    if (t >= k) return query(u<<1, l, r, k);
    else return query(u<<1|1, l, r, k-t);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), nums.pb(w[i]);
    for (int i = 0; i < m; i ++){
        char op[3];
        scanf("%s", op);
        if (*op == 'Q'){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            q[i] = {1, l, r, k};
        }
        else {
            int x, y;
            scanf("%d%d", &x, &y);
            q[i] = {0, x, y};
            nums.pb(y);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    build(1, 0, nums.size()-1);
    for (int i = 1; i <= n; i ++){
        change(1, find(w[i]), i, 1);
    }
    for (int i = 0; i < m; i ++){
        if (q[i].o == 1){
            int l = q[i].l, r = q[i].r, k = q[i].x;
            printf("%d\n", nums[query(1, l, r, k)]);
        }
        else {
            int x = q[i].l, y = q[i].r;
            change(1, find(w[x]), x, -1);
            w[x] = y;
            change(1, find(y), x, 1);
        }
    }
    return 0;
}