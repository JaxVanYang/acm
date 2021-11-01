/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-19 20:53:45
 * @LastEditTime: 2021-10-19 21:24:18
 */

#include <iostream>

using namespace std;
int g[110][110];
int s[110];
int sc[110];
int maxv, maxs, ans;

int main(){

    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            s[i] += g[i][j], s[i] -= g[j][i];
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if (i == j) continue;
            if (g[i][j] == g[j][i]) sc[i] ++, sc[j] ++;
            else {
                if (g[i][j] > g[j][i]) sc[i] += 3;
                else sc[j] += 3;
            }
        }
    }
    for (int i = 1; i <= n;  i++){
        if (sc[i] > maxv) maxv = sc[i], maxs = s[i], ans = i;
        else if (sc[i] == maxv){
            if (maxs < s[i]){
                maxs = s[i], ans  = i;
            }
        }
    }
    int num = 0;
    for (int i = 1; i <= n; i ++){
        if (sc[i] == maxv && maxs == s[i]) num ++;
    }
    if (num > 1) cout << "play-offs";
    else cout << ans << endl;
    return 0;
}