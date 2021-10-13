#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n;
    ll t;
    cin >> n >> t;
    int minV = INT32_MAX;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minV = min(minV, a[i]);
    }

    ll cnt = 0;

    while (t >= minV) {

        ll sum = 0;
        int tmp = 0;
        for (size_t i = 0; i < n; ++i) {
            if (t - sum >= a[i]) {
                ++tmp;
                sum += a[i];
            }
        }

        cnt += t / sum * tmp;
        t %= sum;
    }
    cout << cnt << endl;
}