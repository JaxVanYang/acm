/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/973/C
来源：牛客网

Windy定义了一种Windy数：不含前导零且相邻两个数字之差至少为2的正整数被称为Windy数。
Windy想知道，在A和B之间，包括A和B，总共有多少个Windy数？
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-13 15:00:02
 * @LastEditTime: 2021-07-13 15:00:56
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 13;

int f[N][N];

void init(){
    for (int i = 0; i <= 9; i ++) f[1][i] = 1;
    for (int i = 2; i < N; i ++){
        for (int j = 0; j <= 9; j ++){
            for (int k = 0; k <= 9; k ++){
                if (abs(j - k) >= 2) f[i][j] += f[i-1][k];
            }
        }
    }
}

int dp(int x){
    if (!x) return 0;
    vector<int> nums;
    while (x) nums.push_back(x % 10), x /= 10;
    int res = 0, last = -2;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = i == nums.size()-1; j < v; j ++){
            if (abs(j-last) >= 2){
                res += f[i+1][j];
            }
        }
        if (abs(v - last) >= 2) last = v;
        else break;
        if (!i) res ++;
    }
    // 特殊处理有前导零的数
    for (int i = 1; i < nums.size(); i ++){
        for (int j = 1; j <= 9; j ++){
            res += f[i][j];
        }
    }
    return res;
}

int main(){
    
    int l, r;
    cin >> l >> r;
    init();
    cout << dp(r) - dp(l-1) << endl;
    return 0;
}