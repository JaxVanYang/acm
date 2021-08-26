#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e6 + 10;
int dp[N], sum[N];

int main() {
    int n, m;
    cin >> n >> m;

    dp[1] = sum[1] = 1 % m;

    for (int i = 2; i <= n; ++i) {
        dp[i] = sum[i - 1];

        for (int j = 2; j < i / j; ++j) {
            dp[i] = (dp[i] + dp[i / j]) % m;
        }

        for (int j = 1; j <= i / j; ++j) {
            dp[i] = (dp[i] + (ll)(i / j - i / (j + 1)) * dp[j]) % m;
        }

        sum[i] = (sum[i - 1] + dp[i]) % m;
    }

    cout << dp[n] << endl;
}