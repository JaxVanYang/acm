#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;
template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair
#define Sort(v) sort(v.begin(), v.end())
#define Unique(v) unique(v.begin(), v.end())
#define Lower(v, val) lower_bound(v.begin(), v.end(), val)
#define Upper(v, val) upper_bound(v.begin(), v.end(), val)
#define Reverse(v) reverse(v.begin(), v.end())

const char el = '\n';
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

const int N = 1e6 + 10;
const int mod = 998244353;

ll quick(ll x, ll y) {
    ll ret = 1;

    if (y < 0) return ret;

    x %= mod;

    while (y) {
        if (y & 1) ret = ret * x % mod;

        y >>= 1;
        x = x * x % mod;
    }

    return ret;
}

inline ll inv(ll n) {
    return quick(n, mod - 2);
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ll ans = 1;

    for (int i = 0; i < n - 1; ++i) {
        ans = ans * (m - i) % mod;
    }

    ll div = 1;
    for (int i = 1; i <= n - 1; ++i) {
        div = div * i % mod;
    }

    ans = ans * inv(div) % mod;

    ans = ans * (n - 2) % mod;

    ans = ans * quick(2, n - 3) % mod;

    cout << ans << endl;
}
