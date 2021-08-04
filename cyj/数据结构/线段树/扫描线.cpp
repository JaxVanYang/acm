/*
 * @Descripttion: 
    求矩形面积并
 * @Topic link: https://www.acwing.com/problem/content/description/249/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-02 11:16:24
 * @LastEditTime: 2021-08-02 11:18:05
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e4 + 10;

#define pb push_back
int n;
struct segment{
    double x, y1, y2;
    int k;
    bool operator< (const segment & m){
        return x < m.x;
    }
}seg[N * 2];

struct node{
    int l, r;
    int cnt;
    double len;
}tr[N * 2 * 4];
vector<double> nums;

int find(double x){
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0, 0};
    if (l != r){
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
    }
}

void pushup(int u){
    if (tr[u].cnt){
        tr[u].len = nums[tr[u].r + 1] - nums[tr[u].l];
    }
    else if (tr[u].l != tr[u].r){
        tr[u].len = tr[u<<1].len + tr[u<<1|1].len;
    }
    else tr[u].len = 0; // 叶节点cnt减为0时len赋为0
}

void modify(int u, int l, int r, int k){
    if (tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += k;
        pushup(u);
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u<<1, l, r, k);
        if (r > mid) modify(u<<1|1, l, r, k);
        pushup(u);
    }
}

int main(){
    int T = 1;
    while (scanf("%d", &n), n){
        nums.clear();
        for (int i = 0, j = 0; i < n; i ++){
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            nums.pb(y1), nums.pb(y2);
            seg[j ++] = {x1, y1, y2, 1};
            seg[j ++] = {x2, y1, y2, -1};
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        sort(seg, seg + n * 2);
        build(1, 0, nums.size() - 2); // 注意线段树中存的是区间
        double res = 0;
        for (int i = 0; i < n * 2; i ++){
            if (i) res += tr[1].len * (seg[i].x - seg[i-1].x);
            // 当x相同时,seg i 与seg i-1 x相同, 不会重复计算
            modify(1, find(seg[i].y1), find(seg[i].y2)-1, seg[i].k);
        }
        printf("Test case #%d\n", T ++);
        printf("Total explored area: %.2lf\n\n", res);
    }
    
    return 0;
}