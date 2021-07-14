/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/973/D
来源：牛客网

由于科协里最近真的很流行数字游戏，某人又命名了一种取模数，这种数字必须满足各位数字之和\bmod NmodN为0。
现在大家又要玩游戏了，指定一个整数闭区间[a,b]，问这个区间内有多少个取模数。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-13 15:45:17
 * @LastEditTime: 2021-07-13 15:46:33
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12, M = 105;

int f[N][10][M]; // i位数最高位为j且各位之和modP的值为M的数的个数
int l ,r, P;

int mod(int x, int y){
    return (x % y + y) % y;
}

void init(){
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i ++) f[1][i][i % P] = 1;
    for (int i = 2; i < N; i++){
        for (int j = 0; j <= 9; j ++){
            for (int p = 0; p < P; p ++){
                for (int k = 0; k <= 9; k ++){
                    f[i][j][p] += f[i-1][k][mod(p-j, P)];
                }
            }
        }
    }
}

int dp(int x){
    if (!x) return 1;
    vector<int> nums;
    while (x) nums.push_back(x % 10), x /= 10;
    int res = 0, sum = 0;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = 0; j < v; j ++){
            res += f[i+1][j][mod(-sum, P)];
        }
        sum += v;
        if (!i && sum % P == 0) res ++;
    }
    return res;
}

int main(){
    while (cin >> l >> r >> P){
        init();
        cout << dp(r) - dp(l-1) << endl;
    }
    
    return 0;
}