/*
 * @Descripttion: 送礼物 双向深搜
 * @Topic link: https://www.acwing.com/problem/content/description/173/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-30 16:23:01
 * @LastEditTime: 2021-03-30 16:26:45
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1 << 25;
typedef long long LL;

int w[50], weight[N];
int n, m, cnt = 1, ans, k;

void dfs(int u, int s){
    if (u == k){
        weight[cnt ++] = s;
        return;
    }
    dfs(u + 1, s);
    if ((LL)w[u] + s <= m) dfs(u + 1, s + w[u]);
}

void dfs2(int u, int s){
    if (u == n){
        int l = 0, r = cnt - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if ((LL)weight[mid] + s <= m) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, weight[l] + s);
        return;
    }
    dfs2(u + 1, s);
    if ((LL)s + w[u] <= m) dfs2(u + 1, s + w[u]);
}

int main(){

    cin >> m >> n;
    for (int i = 0; i < n; i ++) cin >> w[i];
    sort(w, w + n);
    reverse(w, w + n);

    k = n / 2; // 此处k的取值应权衡2^k与2^(n-k) * log(2^k)(即是2^(n-k)*k)的大小
    if (n > 2) k += 2; // 当n大于2时，k += 2，否则df2中进入是k已大于n，爆栈
    dfs(0, 0);

    sort(weight, weight + cnt);
    cnt = unique(weight, weight + cnt) - weight;
    dfs2(k, 0);
    cout << ans << endl;
    return 0;
}

