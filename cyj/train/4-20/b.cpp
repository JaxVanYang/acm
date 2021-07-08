/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-20 14:03:23
 * @LastEditTime: 2021-04-20 14:11:34
 */

#include <iostream>

using namespace std;
const int N = 1010;
int n;
int g[N][N];

int main(){

    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> g[i][j]; 
            if (g[i][j] == -1) x = i, y = j;
        }
    }
    if (x == 1 && y == 1) cout << g[x + 1][y] + g[x][y + 1] - g[x + 1][y + 1];
    else if (x == 1){
        cout << g[x+1][y] + g[x][y-1] - g[x+1][y-1];
    } 
    else if (y == 1){
        cout << g[x-1][y] + g[x][y + 1] - g[x-1][y +1];
    }else cout << g[x][y-1] + g[x-1][y] - g[x-1][y-1];

    return 0;
}