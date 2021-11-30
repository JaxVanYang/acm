#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <functional>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>

#define PII pair<int, int>
#define vec vector
#define str string
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
using namespace std;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const int mod = 998244353;
const int N   = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const ll  INF = 1e18;
const db eps = 1e-8;

int T;

ll inv[N], fac[N];

void init(int n) {
  fac[0] = fac[1] = 1, inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  }
  for (int i = 2; i <= n; i++) {
    inv[i] = inv[i] * inv[i - 1] % mod;
  }
}

ll C(ll a, ll b) {
  if (a < 0 || b < 0) return 0;
  if (a <= b) return (ll) (a == b);
  return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

ll solve(ll n, ll m, ll k) {
  ll res = 0, sgn = 1;
  for (ll i = 0; i <= m; i++, sgn *= -1LL) {
    res = (res + mod + sgn * C(m, i) % mod * C(n - i * (k + 1) + m - 1, m - 1) % mod) % mod;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, m, k; cin >> n >> m >> k;

  if (n == m && m == k) return cout << 1, 0;
  if (n < m || m < k) return cout << 0, 0;

  init(2e5);

  if (k == 1) return cout << C(n - m + 1, m), 0;
  if (k == 0) return cout << (m ? 0 : 1), 0; // O(m^2)

  ll ans = 0;

  for (ll i = 1; m >= i * k; i++) {
    ans = (ans + C(n - m + 1, i) * solve(m - i * k, n - m + 1 - i, k - 1) % mod) % mod;
  }

  cout << ans;
  return 0;
}
