#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll n;
    scanf("%lld", &n);

    vector<int> a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }

    sort(a.begin(), a.end(), greater<int>());

    ll ans = 0;

    for (int mask = 1; mask < (1 << a.size()); ++mask) {
        ll x = 0, y = 0;

        for (int i = 0; i < a.size(); ++i) {
            if ((mask >> i) & 1) {
                x = x * 10 + a[i];
            } else {
                y = y * 10 + a[i];
            }
        }

        ans = max(ans, x * y);
    }

    printf("%lld\n", ans);
}