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

const int mod = 1e9 + 7;
const int N   = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const ll  INF = 1e18;
const db eps = 1e-8;

int T;

str s;

int n;
ll mat[105][105];

ll qpow(ll x, ll n, ll mod) {
  ll res = 1;
  for (x %= mod; n; n >>= 1, x = 1LL * x * x % mod)
    if (n & 1) res = 1LL * res * x % mod;
  return res;
}

int gauss() {
  ll det = 1LL;
  for (int i = 1, now = 1; i <= n; i++, now++) {
    ll t = qpow(mat[now][i], mod - 2, mod);
    det = det * mat[now][i] % mod;
    for (int j = 1; j <= n; j++) mat[now][j] = mat[now][j] * t % mod;
    for (int j = 1; j <= n; j++)
      if (j ^ now) {
        t = mat[j][i];
        for (int k = 1; k <= n; k++) 
          mat[j][k] = (mat[j][k] - t * mat[now][k] % mod + mod) % mod;
      }
  }
  return det;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  for (cin >> T; T--; ) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> mat[i][j];
        mat[i][j] = (mat[i][j] % mod + mod) % mod;
      }
    }
    int m = 0;
    for (char c : s) m = (m * 10LL + c - '0') % mod;
    cout << (m == gauss() ? '+' : '-') << '\n';
  }
  return 0;
}
