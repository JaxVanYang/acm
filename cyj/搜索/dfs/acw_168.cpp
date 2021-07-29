/*
 * @Descripttion: 生日蛋糕
 * @Topic link: https://www.acwing.com/problem/content/170/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-26 20:11:07
 * @LastEditTime: 2021-03-29 22:10:04
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 22, INF = 1e9;

int mins[N], minv[N];
int r[N], h[N];
int n, m, ans = INF;

void dfs(int u, int v, int s){
    if (v + minv[u] > n) return; // 可行性剪枝，当当前体积加上剩余u层的最小体积也会超过n时，退出分支
    if (s + mins[u] > ans) return; // 最优性剪枝
    if (s + 2 * (n - v) / r[u+1]  >= ans) return; // 推导底面积公式与体积公式之间的关系得出的不等式，
                                                  // 当当前的面积加上剩余面积可能的最小值也比ans大时，退出
    if (!u){
        if (v == n) ans = s;
        return;
    }
    
    for (int i = min((int)sqrt(n-v), r[u+1]-1); i >= u; i --){ // 枚举符合条件的r，与h
        for (int j = min((n-v)/ i / i, h[u+1]-1); j >= u; j --){
            int t = 0;
            if (u == m) t += i * i; // 当为第m层时，加上总的上表面积
            h[u] = j, r[u] = i;
            dfs(u-1, v + i * i * j, s + t + 2 * i * j);
        }
    }
}

int main(){

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        minv[i] = i * i * i + minv[i - 1]; // 预处理上面i层的最小体积与面积
        mins[i] = 2 * i * i + mins[i - 1];
    }
    r[m + 1] = h[m + 1] = INF;
    dfs(m, 0, 0);
    if (ans == INF) ans = 0;

    cout << ans << endl;


    return 0;
}