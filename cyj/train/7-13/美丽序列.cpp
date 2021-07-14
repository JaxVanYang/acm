/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-13 09:02:23
 * @LastEditTime: 2021-07-13 09:06:01
 */
/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/21313
来源：牛客网

牛牛喜欢整数序列，他认为一个序列美丽的定义是
1：每个数都在0到40之间
2：每个数都小于等于之前的数的平均值
具体地说：for each i, 1 <= i < N,  A[i] <= (A[0] + A[1] + ... + A[i-1]) / i.
3：没有三个连续的递减的数

现在给你一个序列，每个元素是-1到40，你可以将序列中的-1修改成任意的数，求你可以得到多少个美丽序列，答案对1e9+7取模
 * @Topic link: https://ac.nowcoder.com/acm/problem/21313
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-13 09:02:23
 * @LastEditTime: 2021-07-13 09:04:12
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 45, mod=  1e9 + 7;

int f[N][N][3][1610]; // 处理到第i个数且第i个数为v是连续递减序列的第k个，当前和为s的方案数量
int n, a[N];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    if (a[1] == -1){
        for (int i = 0; i <= 40; i ++){
            f[1][i][1][i] = 1;
        }
    } else f[1][a[1]][1][a[1]] = 1;
    for (int i = 2; i <= n; i ++){
        if (a[i] == -1){
            for (int v = 0; v <= 40; v ++){
                for (int p = 0; p <= 40; p ++){
                    for (int k = 1; k <= 2; k ++){
                        for (int s = v * (i-1); s <= 1600 - v; s ++){  // s从v*（i-1）开始枚举
                            if (v >= p){
                                f[i][v][1][s + v] = (f[i][v][1][s+ v] + f[i-1][p][k][s]) % mod;
                            }
                            else {
//                                 if ( i == 3 && v == 0 && s == 8 && f[i-1][p][1][s]) {
//                                     cout << i-1 << ' ' << p << ' ' << 1 << ' ' << s << endl;
//                                 }
                                f[i][v][k][s + v] = (f[i][v][k][s + v] + f[i-1][p][k-1][s]) % mod;
                            }
                        }
                    }
                }
            }
        } else {
            for (int p = 0; p <= 40; p ++){
                for (int k = 1; k <= 2; k ++){
                    for (int s = a[i] * (i-1); s <= 1600 - a[i]; s ++){
                        if (a[i] >= p){
                            f[i][a[i]][1][s + a[i]] = (f[i][a[i]][1][s + a[i]] + f[i-1][p][k][s]) % mod;
                        }else {
                            f[i][a[i]][k][s + a[i]] = (f[i][a[i]][k][s + a[i]] + f[i-1][p][k-1][s]) % mod;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int v = 0; v <= 40; v ++){
        for (int j = 1; j <= 2; j ++){
            for (int s = v * n; s <= 1600; s ++){
                res = (res + f[n][v][j][s]) % mod;
            }
        }
    }
    cout << res << endl;
    return 0;
}
