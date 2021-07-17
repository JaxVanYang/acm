/*
 * @Descripttion: 
给定两个正整数a和b，求在[a,b]中的所有整数中，每个数码(digit)各出现了多少次。
 * @Topic link: https://ac.nowcoder.com/acm/contest/973/G
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-14 20:47:01
 * @LastEditTime: 2021-07-14 20:59:55
 */

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 14;

ll f[N][10][10]; // i位数，最高位为j的数含有u数码的个数
ll power[N];

void init(){
    power[0] = 1;
    for (int i = 1; i < N; i ++) power[i] = power[i-1] * 10;
    for (int i = 0; i < 10; i ++){
        f[1][i][i] = 1;
    }
    for (int i = 2; i < N; i ++){
        for (int j = 0; j < 10; j ++){
            for (int u = 0; u < 10; u ++){
                if (j == u) f[i][j][u] += power[i-1];
                for (int k = 0; k < 10; k ++){
                    f[i][j][u] += f[i-1][k][u];
                }
            }
        }
    }
}

ll dp(ll x, int u){
    if (!x) return u ? 0 : 1;
    vector<int> nums;
    while (x) nums.push_back(x % 10), x /= 10;
    ll res = 0, last = 0; // last记录前面有多少个u
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = (i == nums.size()-1); j < v; j ++){ // 不能含前导0，第一位从1开始枚举
            res += f[i + 1][j][u];
        }
        res += last * v * power[i];
        if (v == u) last ++;
        if (!i) res += last;
    }
    for (int i = 1; i < nums.size(); i ++){ // 对于不含前导0的低位数，除0之外我们如此计算，0另外考虑
        for (int j = 1; j < 10; j ++){ 
// 网上见到写为 j =（i ！= nums.size()）,若nums仅有一位，上处for中不考虑首位为0，
// 此处又只考虑nums.size-1位，不会进入循环，导致0没有判断
            res += f[i][j][u];
        }
    }
    if (!u) res ++; // 考虑0
    return res;
}

int main(){
    init();
    ll l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
   for (int i = 0; i < 10; i ++){
       cout << dp(r, i) - dp(l-1, i);
       if (i == 9) cout << endl;
       else cout << ' ';
   }
     return 0;
}