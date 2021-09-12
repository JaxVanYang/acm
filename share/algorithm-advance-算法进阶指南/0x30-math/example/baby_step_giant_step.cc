#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll x, ll y, ll p) {
    ll ret = 1 % p;
    x %= p;

    while (y) {
        if (y & 1) {
            ret = ret * x % p;
        }

        y >>= 1;
        x = x * x % p;
    }

    return ret;
}

// calculate the minimum non-negtive x such that a^x % p = b % p
int baby_step_giant_step(int a, int b, int p) {
    b %= p;
    if (1 == b) {
        return 0;
    }
    
    map<int, int> mp;

    int t = ceil(sqrt(p));

    cout << "b = " << b << " t = " << t << endl;

    for (int j = 0; j < t; ++j) {
        int val = b * power(a, j, p) % p;
        mp[val] = j;


    }

    a = power(a, t, p);

    for (int i = 0; i <= t; ++i) {
        int val = power(a, i, p);
        if (mp.count(val)) {
            int j = mp[val];

            if (i * t - j >= 0) {
                return i * t - j;
            }
        }
    }

    return -1;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;

    cout << baby_step_giant_step(a, b, p) << endl;
}