/*
 * @Descripttion: 
    线性dp，f[i][j] 表示以第i个字符为结尾的所有数之和%3为j的所有子序列的数量
    答案为所有f[i][0]之和
 * @Topic link: https://ac.nowcoder.com/acm/problem/21302
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-08 10:38:31
 * @LastEditTime: 2021-07-08 10:51:47
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55, mod = 1e9 + 7;

char s[N];
int f[N][3];

int main(){
    
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++){
        int v = s[i] - '0';
        for (int j = 0; j < i; j ++){
            for (int k = 0; k < 3; k ++){
                f[i][k] = (f[i][k] + f[j][(k-(v%3) + 3) % 3]) % mod;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = (res + f[i][0]) % mod;
    cout << res << endl;
    return 0;
}