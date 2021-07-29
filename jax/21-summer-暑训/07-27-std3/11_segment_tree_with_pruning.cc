#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 1e6 + 10;
clock_t startTime;

double getCurTime() {
    return (double)clock() / CLOCKS_PER_SEC;
}

map<pair<ll, ll>, ll> mp;

inline ll is_power(ll x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x >>= 1;
    }
    return cnt == 1;
}

// ll dfs(ll n, ll k) {
//     if (n <= k) return 1;
//     ll half = n / 2;
//     return dfs(half, k) + dfs(n - half, k) + 1;
// }

ll g(ll x) {
    if (x == 1) return 1;
    ll rem = x & 1;
    return x - rem + g((x >> 1) + rem);
}

ll f(ll n, ll k) {
    auto p = MP(n, k);
    if (mp.count(p)) return mp[p];
    ll ret;
    // cout << "n = " << n << " k = " << k << el;
    if (n <= k) ret = 1;
    else if (is_power(n)) ret = g(n / k + (n % k == 0 ? 0 : 1));
    else if (n & 1) ret = 1 + f(n >> 1, k) + f((n >> 1) + 1, k);
    else ret = 1 + (f(n >> 1, k) << 1);
    mp[p] = ret;
    return ret;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << f(n, k) << el;
}

// void test() {
//     for (int i = 1; i < 20; ++i) {
//         cout << "i = " << i << ":" << el;
//         for (int j = 1; j <= i; ++j) {
//             // cout << dfs(i, j) << ':' << g(i / j + (i % j == 0 ? 0 : 1)) << ' ';
//             cout << dfs(i, j) << ':' << f(i, j) << ' ';
//         }
//         cout << el << el;
//     }
// }

int main() {
    // startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << f(2, 1) << el;
    // cout << f(1, 1) << el;

    // test();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // cout << "Elapsed: " << getCurTime() << " s" << el;
}
