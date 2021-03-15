#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 7;
char a[maxn], b[maxn], p[2 * maxn];

// 用来算字符串数字对 mod 取余的值
int get(char s[], int len, int mod) {
    int ret = 0, tmp = 1;
    for (int i = len - 1; i >= 0; --i) {
        ret = (ret + (ll)(s[i] - '0') * tmp) % mod;
        tmp = ((ll)tmp * 10) % mod;
    }
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
        mod = (ll)mod * 10 % maxn;
    }
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