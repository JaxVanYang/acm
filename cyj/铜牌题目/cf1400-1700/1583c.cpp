/*
 * @Descripttion: 找规律
 * @Topic link: https://codeforces.ml/problemset/problem/1583/C
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-26 20:17:06
 * @LastEditTime: 2021-10-26 20:56:06
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;

int s[N];
vector<string> g;
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    g.resize(n);
    for (int i = 0; i < n; i ++) cin >> g[i];
    for (int i = 1; i < n; i ++){
        for (int j = 1; j < m; j ++){
            if (g[i-1][j] == 'X' && g[i][j-1] == 'X') s[j] ++;
        }
    }
    for (int i = 1; i < m; i ++) s[i] += s[i-1];
    int q;
    cin >> q;
    while (q --){
        int a,b;
        cin >> a >> b;
        a --, b --;
        if (s[b]-s[a]) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}