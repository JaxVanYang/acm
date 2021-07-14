/*
 * @Descripttion: 链接：https://ac.nowcoder.com/acm/contest/973/B
来源：牛客网

科协里最近很流行数字游戏。某人命名了一种不降数，这种数字必须满足从左到右各位数字成小于等于的关系，如123，446。
现在大家决定玩一个游戏，指定一个整数闭区间[a,b]，问这个区间内有多少个不降数。
 
 * @Topic link: https://ac.nowcoder.com/acm/contest/973/B
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-13 14:18:57
 * @LastEditTime: 2021-07-13 14:20:11
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 12;

int f[N][10];
int l, r;

void init(){
    for (int i  = 0; i <= 9; i ++) f[1][i] = 1; // i位，且最高位为j的不降数方案个数
    for (int i = 2; i < N; i ++){
        for (int j = 0; j <= 9; j ++){
            for (int k = j; k <= 9; k ++){
                f[i][j] += f[i-1][k];
            }
        }
    }
}

int dp(int x){
    if (!x) return 1;
    vector<int> nums;
    
    while (x) nums.push_back(x % 10), x /= 10;
    int res = 0, last = 0;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = last; j < v; j ++){
            res += f[i+1][j];
        }
        if (last > v) break;
        last = v;
        if (!i) res ++;
    }
    return res;
}

int main(){

    init();
    while (cin >> l >> r) cout << dp(r) - dp(l-1) << endl;
    return 0;
}