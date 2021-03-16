/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-15 11:42:11
 * @LastEditTime: 2021-03-16 16:21:22
 */
// ac
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
char a[N], b[N], p[2 * N];


int get(char s[], int len, int mod) {
    int ret = 0, tmp = 1;
    for (int i = len - 1; i >= 0; --i) {
        ret = (ret + (ll)(s[i] - '0') * tmp) % mod;
        tmp = ((ll)tmp * 10) % mod;
        // cout << tmp  << " " ;
        // cout << ret << " ";
    }
    // cout << endl;
    
    return ret;
}

int main() {
    int len1, len2, len3;
    cin >> len1 >> len2 >> len3;
    scanf("%s%s%s", a, b, p);
    // cout << a << endl << b << endl << p << endl;
    // cout << "a mod  = " << get(a, len1, 3) << endl;
    int k = 0;
    while (p[k] != '*') ++k;
    int mod = 1;
    // 选取 mod 值
    for (int i = 0; i < len3 - k; ++i) {
        mod = (ll)mod * 10 % N;
    }
    // cout << "mod " << mod << endl;
    for (int i = 0; i <= 9; ++i) {
        p[k] = '0' + i;
        int amod = get(a, len1, mod), bmod = get(b, len2, mod);
        int pmod = get(p, len3, mod);
        if ((ll)amod * bmod % mod == pmod) {
            printf("%d\n", i);
            return 0;
        }
    }
}