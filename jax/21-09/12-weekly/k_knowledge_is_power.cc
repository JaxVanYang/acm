#include <bits/stdc++.h>
using namespace std;

int solve() {
    int x;
    cin >> x;

    int ans = -1;

    if (x & 1) {
        ans = 1;
    } else if (x % 3 == 0 && x > 6) {
        ans = 2;
    } else if (x % 4 == 0) {
        ans = 2;
    } else if (x % 3 == 1 && x > 7) {
        int k = x / 3;
        if (__gcd(k - 1, k + 2) == 1) {
            ans = 3;
        } else {
            ans = 4;
        }
    } else if (x % 3 == 2 && x > 8) {
        int k = x / 3;
        if (__gcd(k - 1, k + 2) == 1) {
            ans = 3;
        } else {
            ans = 4;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}