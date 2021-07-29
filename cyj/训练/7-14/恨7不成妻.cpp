/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/973/F
来源：牛客网

最终，他发现原来这一切归根到底都是因为和7有关！所以，他现在甚至讨厌一切和7有关的数！
什么样的数和7有关呢？如果一个整数符合下面三个条件之一，那么我们就说这个整数和7有关：
整数中某一位是7；
整数的每一位加起来的和是7的整数倍；
这个整数是7的整数倍。
现在问题来了：吉哥想知道在一定区间内和7无关的数字的平方和。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-14 10:44:22
 * @LastEditTime: 2021-07-14 10:44:22
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 22, P = 1e9 + 7;
typedef long long ll;

struct node {
    ll s0, s1, s2; // 分别记录数量s0，A之和s1， A^2之和s2
}f[N][10][7][7];
int power7[N], power9[N];

int mod(ll x, int y){
    return (x % y + y) % y;
}

void init(){
    for (int i = 0; i <= 9; i ++){
        if (i == 7) continue;
        auto &t = f[1][i][i%7][i%7];
        t.s0 ++;
        t.s1 += i;
        t.s2 += i * i;
    }
    ll power = 10;
    for (int i = 2; i < N; i ++, power *= 10){
        for (int j = 0; j <= 9; j ++){
            if (j == 7) continue;
            for (int p = 0; p < 7; p ++){
                for (int s = 0; s < 7; s ++){
                    for (int k = 0; k <= 9; k ++){
                        if (k == 7) continue;
                        auto &t1 = f[i][j][p][s], &t2 = f[i-1][k][mod(p-j, 7)][mod(s-j*(power % 7), 7)];
                        t1.s0 = (t1.s0 + t2.s0) % P;
                        t1.s1 = (t1.s1 + (j * (power % P)) % P * t2.s0 % P + t2.s1) % P;
                        t1.s2 = ( 
                            t1.s2 + 
                            j * j * (power % P) % P * (power % P) % P * t2.s0 % P + 
                            2 * j * (power % P) % P * t2.s1 % P +
                            t2.s2 % P
                        ) % P;
                    }
                }
            }
        }
    }
    power7[0] = power9[0] = 1;
    for (int i = 1; i < N; i ++){
        power7[i] = power7[i-1] * 10ll % 7;
        power9[i] = power9[i-1] * 10ll % P;
    }
}

node get(int i, int j, int a, int b){
    node res = {0, 0, 0};
    for (int x = 0; x < 7; x ++){
        for (int y = 0; y < 7; y ++){
            if (a == x || b == y) continue;
            auto &t = f[i][j][x][y];
            res.s0 = (res.s0 + t.s0) % P;
            res.s1 = (res.s1 + t.s1) % P;
            res.s2 = (res.s2 + t.s2) % P;
        }
    }
    
    return res;
}

ll dp(ll x){
    if (!x) return 0;
    ll backup = x % P;
    vector<int> nums;
    while (x) nums.push_back(x % 10), x /= 10;
    ll res = 0, last_p = 0, last_s = 0;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = 0; j < v; j ++){
            if (j == 7) continue;
            int a = mod(-last_p, 7);
            int b = mod(-last_s % 7 * power7[i+1], 7);
            auto t = get(i+1, j, a, b);
            res = (res + 
                  (last_s % P) * (last_s % P) % P  * power9[i+1] % P * power9[i+1] % P * t.s0 % P +
                   2 * (last_s % P) % P * t.s1 % P * power9[i+1] % P + 
                   t.s2 % P
                  ) % P;
        }
        if (v == 7) break;
        last_p += v;
        last_s = last_s * 10 + v;
        if (!i && last_s % 7 && last_p % 7) res = (res + backup * backup % P) % P;
    }
    return res;
}

int main(){
    init();
    int T;
    cin >> T;
    while (T --){
        ll l, r;
        cin >> l >> r;
        cout << mod(dp(r) - dp(l-1), P) << endl; // 结果可能为负余数，结果再取一次余
    }
    return 0;
}