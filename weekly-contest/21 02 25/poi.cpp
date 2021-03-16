/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-03 20:23:36
 * @LastEditTime: 2021-03-03 22:23:02
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 3000005, P = 1e9 + 7;

LL d[N][4];
char s[N];
int n;

int main(){

    cin >> n >> s + 1;
    
    memset(d, 0, sizeof d);
    d[0][3] = 1;
    for (int i = 1; i <= n; i ++){
        if (s[i] == '*'){
            d[i][0] = ((d[i-1][0] * 3) % P + d[i-1][3]) % P;
            d[i][1] = ((d[i-1][1] * 3) % P + d[i-1][0]) % P;
            d[i][2] = ((d[i-1][2] * 3) % P + d[i-1][1]) % P;
            d[i][3] = (d[i-1][3] * 3) % P;
        }
        else if (s[i] == 'p'){
            d[i][0] = (d[i-1][0] + d[i-1][3]) % P;
            d[i][1] = d[i-1][1];
            d[i][2] = d[i-1][2];
            d[i][3] = d[i-1][3];
        }
        else if (s[i] == 'o'){
            d[i][0] = d[i-1][0];
            d[i][1] = (d[i-1][0] + d[i-1][1]) % P;
            d[i][2] = d[i-1][2];
            d[i][3] = d[i-1][3];

        }
        else {
            d[i][0] = d[i-1][0];
            d[i][1] = d[i-1][1];
            d[i][2] = (d[i-1][2] + d[i-1][1]) % P;
            d[i][3] = d[i-1][3];
        }
    }

    cout << d[n][2] << endl;


    return 0;
}