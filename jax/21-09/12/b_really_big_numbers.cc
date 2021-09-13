#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll x, ll s) {
    ll val = x;

    while (x) {
        val -= x % 10;
        x /= 10;
    }

    return val >= s;
}

int main() {
    ll n, s;
    cin >> n >> s;

    ll l = 1, r = n + 1;

    while (l < r) {
        ll mid = l + r >> 1;

        if (check(mid, s)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << n - l + 1 << endl;
}