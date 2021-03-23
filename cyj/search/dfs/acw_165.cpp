/*
 * @Descripttion: dfs搜索
 * @Topic link: https://www.acwing.com/problem/content/description/167/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 14:12:05
 * @LastEditTime: 2021-03-23 14:20:20
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 20;

int v[N];
int w, c[N];
int n, ans = N;

void dfs(int now, int cnt){
    if (cnt >= ans) return;
    if (now == n + 1) {
        ans = cnt; 
        return;
    }
    for (int i = 1; i <= cnt; i ++){
        if (v[i] + c[now] <= w){
            v[i] += c[now];
            dfs(now + 1, cnt);
            v[i] -= c[now];
        }
    }
    v[cnt + 1] = c[now];
    dfs(now + 1, cnt + 1);
    v[cnt + 1] = 0;
}

int main(){
    cin >> n >> w;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    sort(c + 1, c + 1 + n);
    reverse(c + 1, c + n + 1); // 剪枝，减少搜索分支
    ans = n;
    dfs(1, 0);
    cout << ans << endl;
    
    return 0;
}