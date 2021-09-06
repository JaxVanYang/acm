#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 16;
int v[N + 1];
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

int a, b, c, d;

inline int count(int &n, int p) {
    int ret = 0;

    while (n % p == 0) {
        ++ret;
        n /= p;
    }

    return ret;
}

int Cnt(int p) {
    int ret = 0;
    
    int m_a = count(a, p), m_b = count(b, p);
    int m_c = count(c, p), m_d = count(d, p);

    if (m_a > m_c) {
        if (m_b < m_d && m_c == m_d) {
            ret = 1;
        } else if (m_b == m_d && m_c <= m_d) {
            ret = 1;
        }
    } else if (m_a == m_c) {
        if (m_b < m_d && m_d >= m_c) {
            ret = 1;
        } else if (m_b == m_d && m_c <= m_d) {
            ret = m_d - m_c + 1;
        }
    }

    return ret;
}

void solve() {
    cin >> a >> b >> c >> d;

    int ans = 1;

    for (int p : primes) {
        if (p > d / p) break;

        ans *= Cnt(p);
    }

    if (d > 1) ans *= Cnt(d);

    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        solve();
    }
}