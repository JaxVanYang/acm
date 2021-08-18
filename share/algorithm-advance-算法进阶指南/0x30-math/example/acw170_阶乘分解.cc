#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int v[N];
vector<int> primes;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (v[i] == 0) {
            v[i] = i;
            primes.push_back(i);
        }
        for (int prime : primes) {
            if (prime > min(v[i], n / i)) break;
            v[i * prime] = prime;
        }
    }

    for (int prime : primes) {
        int cnt = 0;
        for (ll p = prime; p <= n; p *= prime) {
            cnt += n / p;
        }
        if (cnt != 0) cout << prime << ' ' << cnt << endl;
    }
}