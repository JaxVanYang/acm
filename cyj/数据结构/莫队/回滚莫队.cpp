/*
 * @Descripttion: 
 JOI 教授决定用如下的方法分析这些日记：

    选择日记中连续的一些天作为分析的时间段
    事件种类 t 的重要度为 t × (这段时间内重要度为 t 的事件数)
    计算出所有事件种类的重要度，输出其中的最大值
    现在你被要求制作一个帮助教授分析的程序，每次给出分析的区间，你需要输出重要度的最大值。
 * @Topic link: https://www.acwing.com/problem/content/2525/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-29 15:16:03
 * @LastEditTime: 2021-07-29 15:17:15
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

struct query{
    int id, l, r;
}q[N];
ll ans[N];
int len, n, m, w[N], cnt[N];
vector<int> nums;

int get(int x){
    return (x-1) / len;
}

bool cmp(const query &a, const query &b){
    int i = get(a.l), j = get(b.l);
    if (i != j) return i < j;
    return a.r < b.r;
}

void add(int x, ll& res){
    cnt[x] ++;
    res = max(res, (ll)cnt[x] * nums[x]);
}

int main(){
    scanf("%d%d", &n, &m);
    len = sqrt(n);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]), nums.push_back(w[i]);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i ++){
        w[i] = lower_bound(nums.begin(), nums.end(), w[i]) - nums.begin();
    }
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        q[i] = {i, a, b};
    }
    sort(q, q + m, cmp);
    
    for (int x = 0; x < m;){
        int y = x;
        while (y < m && get(q[y].l) == get(q[x].l)) y ++;
        // 先暴力处理左右端点同在一个块的情况
        while (x < y && get(q[x].l) == get(q[x].r)){
            ll res = 0;
            int l = q[x].l, r = q[x].r, id = q[x].id;
            for (int i = l; i <= r; i ++){
                add(w[i], res);
            }
            ans[id] = res;
            for (int i = l ;i <= r; i ++) cnt[w[i]] --;;
            x ++;
        }
        int right = get(q[x].l) * len + len - 1;
        int i = right + 1, j = right;
        ll res = 0;
        while(x < y){
            int l = q[x].l, r = q[x].r, id = q[x].id;
            while (j < r) add(w[++ j], res); // 此时右端点已到正确的位置
            ll backup = res;
            while (i > l) add(w[-- i], res);
            ans[id] = res;
            res = backup; // res回退
            // 消去暴力的影响
            while (i < right + 1) cnt[w[i ++]] --; 
            x ++;
        }
        memset(cnt, 0, sizeof cnt);
    }
    for (int i = 0; i < m; i ++) printf("%lld\n", ans[i]);
    return 0;
}
