/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/19973
来源：牛客网

某人有一套玩具，并想法给玩具命名。首先他选择WING四个字母中的任意一个字母作为玩具的基本名字。然后他会根据自己的喜好，将名字中任意一个字母用“WING”中任意两个字母代替，使得自己的名字能够扩充得很长。
现在，他想请你猜猜某一个很长的名字，最初可能是由哪几个字母变形过来的。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-15 14:50:36
 * @LastEditTime: 2021-07-15 15:21:44
 */

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 210, M = 18;

bool ch[5][5][5], f[N][N][5];
unordered_map<char, int> m;
char s[N];

int main(){
    m.insert({'W', 1}), m.insert({'I', 2});
    m.insert({'N', 3}), m.insert({'G', 4});
    int p[5];
    for (int i = 1; i <= 4; i ++) cin >> p[i];
    for (int i = 1; i <= 4; i ++){
        for (int j = 1; j <= p[i]; j ++){
            char x, y;
            cin >> x >> y;
            ch[i][m[x]][m[y]] = 1;
        }
    }
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++){
        f[i][i][m[s[i]]] = 1;
    }
    for (int len = 2; len <= n; len ++){
        for (int l = 1; l + len -1 <= n; l ++){
            int r = l + len - 1;
            for (int k = l; k < r; k ++){
                for (int x = 1; x <= 4; x ++){
                    for (int y = 1; y <= 4; y ++){
                        for (int z = 1; z <= 4; z ++){
                            if (f[l][k][x] && f[k+1][r][y] && ch[z][x][y]){
                                f[l][r][z] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    bool flag = false;
    if (f[1][n][1]) {
        cout << 'W', flag = true;
    }
    if (f[1][n][2]) {
        cout << 'I', flag = true;
    }
    if (f[1][n][3]) {
        cout << 'N', flag = true;
    }
    if (f[1][n][4]) {
        cout << 'G', flag = true;
    }
    if (!flag) cout << "The name is wrong!" << endl;
    return 0;
}