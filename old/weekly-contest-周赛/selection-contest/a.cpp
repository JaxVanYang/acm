/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-13 22:36:35
 * @LastEditTime: 2021-03-13 22:36:50
 */
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5010;

typedef long long LL;

int p[N];
int w[N], v[N], w1[N];
LL v1[N];
LL dp[N];
int cho[N], cnt;
int n , m, P;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    
    cin >> n >> m >> P;
    for (int i = 1; i <= n; i ++) p[i] = i;
    
    for (int i = 1; i <= n ; i ++) cin >> v[i] >> w[i];
    
    for (int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb){
            p[pa] = pb;
        }
    }
    
    for (int i = 1; i <= n; i ++){
        if (p[i] == i) cho[i] = ++ cnt;
    }
    for (int i = 1; i <= n; i ++){
        int pi = find(i);
        w1[cho[pi]] += w[i];
        v1[cho[pi]] += v[i];
    }
    
    for (int i = 0; i <= cnt; i ++){
        for (int j = P; j >= w1[i]; j --){
            dp[j] = max(dp[j], dp[j - w1[i]] + v1[i]);
        }
    }
    
    cout << dp[P] << endl;
    
    return 0;
}