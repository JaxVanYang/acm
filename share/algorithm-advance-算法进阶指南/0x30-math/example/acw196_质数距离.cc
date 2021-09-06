#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1 << 16;
int v[N + 10];
vector<int> primes;
void Prime() {
    for (int i = 2; i <= N; ++i) {
        if (v[i] == 0) {
            v[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > v[i] || p > N / i) break;
            v[i * p] = p;
        }
    }
}
int l, r;

void solve() {
    vector<bool> st(r - l + 1);
    if (l == 1) st[0] = 1;

    for (int p : primes) {
        if (p > r / p) break;
        for (int i = max(2ll, ((ll)l + p - 1) / p); i <= r / p; ++i) {
            st[i * p - l] = true;
        }
    }

    vector<int> ps;
    for (int i = 0; i < r - l + 1; ++i) {
        if (!st[i]) ps.push_back(i + l);
    }

    if (ps.size() < 2) {
        cout << "There are no adjacent primes.\n";
        return;
    }

    int a = ps[0], b = ps[1], c = a, d = b;
    for (int i = 2; i < ps.size(); ++i) {
        int dis = ps[i] - ps[i - 1];
        if (dis < b - a) {
            a = ps[i - 1], b = ps[i];
        } else if (dis > d - c) {
            c = ps[i - 1], d = ps[i];
        }
    }

    cout << a << "," << b << " are cloest, " << c << "," << d << " are most distant.\n";
}

int main() {
    Prime();
    while (cin >> l >> r) {
        solve();
    }
}