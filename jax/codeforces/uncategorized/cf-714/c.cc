#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

int dp[maxn];

void getDp() {
    for (int i = 0; i < 10; ++i) {
        dp[i] = 1;
    }
    for (int i = 10; i < maxn; ++i) {
        dp[i] = (dp[i - 10] + dp[i - 9]) % mod;
    }
}

void solve() {

    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n) {
        ans = ((ll)ans + dp[n % 10 + m]) % mod;
        n /= 10;
    }

    printf("%d\n", ans);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    getDp();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}