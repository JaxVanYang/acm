#include <iostream>
using namespace std;
using ll = long long;

const int maxr = 1e6 + 5;

ll cube_root(ll num) {
    ll l = 0, r = maxr;
    while (l <= r) {
        ll mid = l + r >> 1;
        ll val = mid * mid * mid;
        // cout << "val = " << val << endl;
        if (val == num) {
            return mid;
        }
        if (val < num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

bool check(ll a, ll b) {
    ll mul = a * b;
    ll root = cube_root(mul);
    // cout << "root = " << root << endl;
    if (root == -1) {
        return false;
    }
    return a % root == 0 && b % root == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        if (check(a, b)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}