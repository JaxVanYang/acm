#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
int phi[N], v[N];
vector<int> primes;

void euler(int n) {
    for (int i = 2; i <= n; ++i) {
        if (v[i] == 0) {
            v[i] = i;
            phi[i] = i - 1;

            primes.push_back(i);
        }

        for (int p : primes) {
            if (p > v[i] || p > n / i) break;

            v[i * p] = p;

            phi[i * p] = phi[i] * (i % p ? p - 1 : p);
        }
    }
}

ll sum[N];

void Sum(int n) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = phi[i] + sum[i - 1];
    }
}

inline ll calc(int n) {
    return 2 * sum[n] + 3;
}

int main() {
    euler(N - 1);
    Sum(N - 1);

    int c;
    cin >> c;

    for (int i = 1; i <= c; ++i) {
        int n;
        cin >> n;

        cout << i << ' ' << n << ' ' << calc(n) << endl;
    }
}