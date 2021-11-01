/*
 * @Descripttion: 
     由于从父亲到子节点温度必然递减，我们只需要倍增找出从x出发向上的温度小于等于r的最高的点，在其子树中找温度
     高于l的节点即可，我们使用dfs序将书上问题转化为区间问题，即连续一段中大于l的点的数量，使用主席树求解，将所有点
     离散化后按dfs序加入主席树，每次在父节点dfs序开始的版本到他的子节点结束的版本中查找大于l的即可，即用结束版本减去
     开始版本的前一个版本，同静态求区间第k小的思想
 * @Topic link: https://ac.nowcoder.com/acm/contest/11260/E
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-18 11:36:50
 * @LastEditTime: 2021-08-18 11:41:59
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], idx1, w[N], root[N], idx;
int n, m, f[N][18], dfn[N], timestamp, en[N], pre[N];
vector<int> nums;
struct node {
    int l, r, num;
}tr[N * 4 + 17 * N];

void add(int a, int b){
    e[idx1] = b, ne[idx1] = h[a], h[a] = idx1 ++;
}

int build(int l, int r){
    int q =  ++ idx;
    if (l == r) return q;
    int mid = l + r >> 1;
    tr[q].l = build(l, mid), tr[q].r = build(mid + 1, r);
    return q;
}

void dfs(int u, int fa){
    dfn[u] = ++ timestamp, pre[timestamp] = u;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        f[j][0] = u;
        for (int k = 1; k <= 17; k ++) f[j][k] = f[f[j][k-1]][k-1];
        dfs(j, u);
    }
    en[u] = timestamp;
}

int find(int x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int find_fa(int x, int r){
    for (int i = 17; i >= 0; i --){
        if (f[x][i] && w[f[x][i]] <= r) x = f[x][i];
    }
    return x;
}

int insert(int p, int l, int r, int x){
    int q =  ++ idx;
    tr[q] = tr[p];
    if (l == r){
        tr[q].num ++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid + 1, r, x);
    tr[q].num = tr[tr[q].l].num + tr[tr[q].r].num;
    return q;
}

int query(int p, int q, int l, int r, int x){
    if (l >= x) return tr[q].num - tr[p].num;
    int mid = l + r >> 1;
    int res = 0;
    if (x <= mid) res += query(tr[p].l, tr[q].l, l, mid, x);
    res += query(tr[p].r, tr[q].r, mid + 1, r, x);
    return res;
}    

int main(){
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), nums.push_back(w[i]);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    root[0] = build(0, nums.size()-1);
    dfs(1, -1);
    for (int i = 1; i <= n; i ++){
        root[i] = insert(root[i-1], 0, nums.size()-1, find(w[pre[i]]));
    }
    scanf("%d", &m);
    while (m --){
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);
        if (w[x] > r || w[x] < l) puts("0");
        else {
            int y = find(l);
            int fa = find_fa(x, r);
            printf("%d\n", query(root[dfn[fa]-1], root[en[fa]], 0, nums.size()-1, y));
        }
    }
    return 0;
}