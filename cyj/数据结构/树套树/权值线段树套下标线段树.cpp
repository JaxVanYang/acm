/*
 * @Descripttion: 权值线段树套下标线段树，标记永久化与线段树动态开点， 每次查询log^2n
 你需要维护 n 个可重整数集，集合的编号从 1 到 n。
这些集合初始都是空集，有 m 个操作：

1 l r c：表示将 c 加入到编号在 [l,r] 内的集合中
2 l r c：表示查询编号在 [l,r] 内的集合的并集中，第 c 大的数是多少。

 * @Topic link: https://www.luogu.com.cn/problem/P3332
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-27 11:06:55
 * @LastEditTime: 2021-07-27 13:52:34
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 50005, P = N * 17 * 17, M = N * 4;

struct ndoe {
    int l, r, sum, add;
}tr[P]; // 内层线段树

struct q {
    int op, a, b, c;
}ops[N];
int L[M], R[M], T[M], idx; // 外层线段树
vector<int> nums;
int n, m;

void build(int u, int l, int r){
    L[u] = l, R[u] = r, T[u] = ++ idx;
    if (l == r) return;
    int mid =  l + r >> 1;
    build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
}

int find(int x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int intersection(int a, int b, int c, int d){
    return min(b, d) - max(a, c) + 1;
}

void update(int u, int l, int r, int a, int b){
    tr[u].sum += intersection(l, r, a, b);
    if (l >= a && r <= b){
        tr[u].add ++;
        return;
    }
    int mid = l + r >> 1;
    if (a <= mid){
        if (!tr[u].l) tr[u].l = ++ idx;
        update(tr[u].l, l, mid, a, b);
    }
    if (b > mid){
        if (!tr[u].r) tr[u].r = ++ idx;
        update(tr[u].r, mid+1, r, a, b);
    }
}

int get_sum(int u, int l, int r, int a, int b, int add){
    if (l >= a && r <= b){
        return tr[u].sum + (r-l+1) * add;
    }
    int res = 0;
    int mid = l + r >> 1;
    add += tr[u].add;
    if (a <= mid){
        if (tr[u].l) res += get_sum(tr[u].l, l, mid, a, b, add);
        else res += intersection(l, mid, a, b) * add; 
        // 不存在则代表没有add更新过，直接加上区间长度*当前累加add即可
    }
    if (b > mid){
        if (tr[u].r) res += get_sum(tr[u].r, mid + 1, r, a, b, add);
        else res += intersection(mid+1, r, a, b) * add;
    }
    return res;
}

void change(int u, int l, int r, int c){
    update(T[u], 1, n, l , r);
    if (L[u] == R[u]) return;
    int mid = L[u] + R[u] >> 1;
    if (c <= mid) change(u<<1, l, r, c);
    else change(u<<1|1, l, r, c);
}

int query(int u, int l, int r, int c){
    if (L[u] == R[u]) return L[u];
    int mid = L[u] + R[u] >> 1;
    int k = get_sum(T[u<<1|1],1, n, l, r, 0);
    if (c <= k) return query(u<<1|1, l, r, c);
    else return query(u<<1, l, r, c-k);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int op, a, b, c;
        scanf("%d%d%d%d", &op, &a, &b, &c);
        ops[i] = {op, a, b, c};
        if (op == 1) nums.push_back(c); // 对值域进行离散化
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    build(1, 0, nums.size()-1);
    for (int i = 1; i <= m; i ++){
        int op = ops[i].op, a = ops[i].a, b = ops[i].b, c = ops[i].c;
        if (op == 1){
            change(1, a, b, find(c));
        }
        else printf("%d\n", nums[query(1, a, b, c)]); // 不知道区间中共多少个数，不能转换为求第k小数
    }
    return 0;
}