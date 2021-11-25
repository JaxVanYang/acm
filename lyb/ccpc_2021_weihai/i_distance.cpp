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

const int N   = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll  INF = 1e18;
const db eps = 1e-8;

int T;

ll n, sq;
ll pr[N], cnt;
bitset<N> ok;

ll s[N], h[N];
ll block[N], tot;
int idx1[N], idx2[N];

const ll mod = 1e9 + 7;
const ll inv2 = mod - mod / 2;

ll sum(ll x) {
  x %= mod;
  return (x * (x + 1) % mod * inv2 % mod + mod - 1) % mod;
}

void init() {
  sq = sqrtl(n);
  for (int i = 2; i <= sq; i++) {
    if (!ok[i]) pr[++cnt] = i, s[cnt] = (s[cnt - 1] + i) % mod;
    for (int j = 1; j <= cnt && pr[j] * i <= sq; j++) {
      ok[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  for (ll l = 1; l <= n; l = n / block[tot] + 1) {
    block[++tot] = n / l, h[tot] = sum(block[tot]);
    block[tot] <= sq ? idx1[block[tot]] = tot : idx2[n / block[tot]] = tot;
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= tot && pr[i] * pr[i] <= block[j]; j++) {
      ll tmp = block[j] / pr[i];
      int pos = tmp <= sq ? idx1[tmp] : idx2[n / tmp];
      h[j] = (h[j] - (h[pos] - s[i - 1] + mod) % mod * pr[i] % mod + mod) % mod;
    }
  }
}

ll count(ll p, ll x) {
  ll res = 0;
  for (x /= p; x >= p;) {
    x /= p, res = (res + (n - x) % mod * (x % mod) % mod) % mod;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n, init();
  ll ans = 0;
  for (ll l = 1, r, tmp; l <= n; l = r + 1) {
    tmp = n / l, r = n / tmp;
    tmp %= mod, tmp = (n - tmp) % mod * tmp % mod;
    int pl = (l - 1) <= sq ? idx1[l - 1] : idx2[n / (l - 1)];
    int pr = r <= sq ? idx1[r] : idx2[n / r];
    ans = (ans + (h[pr] - h[pl] + mod) % mod * tmp % mod) % mod;
  }
  for (int i = 1; i <= cnt; i++) {
    ans = (ans + count(pr[i], n) * pr[i] % mod) % mod;
  }
  cout << 2LL * ans % mod;
  return 0;
}
