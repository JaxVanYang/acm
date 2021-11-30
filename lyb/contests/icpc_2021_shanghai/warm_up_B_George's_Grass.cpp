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

#define PII pair<ll, ll>
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

const int mod = 1e9 + 7;
const int N   = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll  INF = 1e18;
const db eps = 1e-8;

int T;

int n, m;
PII A[N], B[N];
ll s[N], ss[N];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i].se;
  for (int i = 1; i <= m; i++) cin >> B[i].se;
  for (cin >> T; T--; ) {
    int op, x; ll tt; cin >> op >> x >> tt;
    (op == 1 ? A : B)[x].fi = tt;
  }
  sort(B + 1, B + 1 + m);
  const function<ll (ll, ll, ll)> mul = [](ll a, ll b, const ll &mod) -> ll {
    a %= mod, b %= mod;
    return a * b % mod;
  };
  for (int i = 1; i <= m + 1; i++) {
    s[i] = s[i - 1] + B[i].se, s[i] %= mod;
    ss[i] = ss[i - 1] + mul(B[i].fi, B[i].se, mod), ss[i] %= mod;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int p = [&](int l, int r, ll lim) -> int {
      int res = r + 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (B[mid].fi >= lim) res = mid, r = mid - 1;
        else l = mid + 1;
      } return res;
    }(1, m, A[i].fi);
    ll sum = mul(A[i].fi, s[p - 1], mod) + (ss[m] - ss[p - 1] + mod) % mod;
    ans = (ans + mul(A[i].se, sum, mod)) % mod;
  }
  cout << ans;
  return 0;
}
