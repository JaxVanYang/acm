#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 10;
int phi[N];
ll sum[N];

void euler(int n) {
    for (int i = 1; i <= n; ++i) phi[i] = i;

    for (int i = 2; i <= n; ++i) if (phi[i] == i) {
        for (int j = i; j <= n; j += i) {
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void Sum(int n) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = phi[i] + sum[i - 1];
    }
}

int main() {
    int n;
    cin >> n;

    euler(n);

    Sum(n);

    ll ans = 0;

    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i - 1) {
            ans += 2 * sum[n / i];
        }
    }

    cout << ans << endl;
}