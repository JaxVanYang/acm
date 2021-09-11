#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 26;
int a[N], m[N];

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }

    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

inline ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> m[i];
    }

    ll x = m[0], p = a[0];

    for (int i = 1; i < n; ++i) {
        ll k, y;        

        ll d = exgcd(p, a[i], k, y);

        if ((m[i] - x) % d) {
            cout << -1 << endl;
            return 0;
        }

        // 因为数据比较极限，所以需要保证每一步都取最小正系数 k
        k *= (m[i] - x) / d;
        ll t = a[i] / d;
        k = (k % t + t) % t;

        x += k * p;
        p = p / d * a[i];
    }

    cout << x << endl;
}