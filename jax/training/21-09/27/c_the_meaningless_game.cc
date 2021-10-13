#include <iostream>
using namespace std;
using ll = long long;

const ll lmt = 1e6 + 10;

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    if (a == 0 && b == 0) {
        puts("Yes");
        return;
    }

    if (a == 0 || b == 0) {
        puts("No");
        return;
    }

    ll res = (ll)a * b;

    ll l = 0, r = lmt;

    while (l < r) {
        ll mid = l + r >> 1;

        if (mid * mid * mid < res) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (a % l || b % l) {
        puts("No");
    } else {
        puts("Yes");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        solve();
    }
}