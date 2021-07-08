/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-05-19 20:18:08
 * @LastEditTime: 2021-05-19 20:23:12
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 55;

int g[N][N];
int main(){
    int n;
    cin >> n;
    for  (int i = 1; i <= n; i ++){
        for (int j= 1; j <= n; j ++){
            cin >> g[i][j];
        }
    }
    bool ans = 1;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            bool suc = false;
            if (g[i][j] != 1){
                for (int k = 1; k <= n; k ++){
                    for (int u = 1; u <= n; u ++){
                        if (k == j || u == i) continue;
                        if (g[i][k] + g[u][j] ==  g[i][j]){
                            suc = 1;
                        }
                    }
                }
                if (!suc) {
                    ans = false;
                    break;
                }
            }
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}