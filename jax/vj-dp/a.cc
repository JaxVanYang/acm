#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
// using ll = long long;
typedef long long ll;
const int N = 13;
const int mod = 1e8;

int dp[N][1 << N], g[1 << N], f[N];

int main() {
  int m, n, ans = 0;
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      f[i] = (f[i] << 1) + x;
    }
  for (int s = 0; s < 1 << n; s++) {
    if (!((s << 1) & s && (s >> 1) & s)) g[s] = 1;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int s = 0; s < 1 << n; s++) {
      if ((s & f[i]) == s && g[s]) {
        for (int k = 0; k < 1 << n; k++) {
          if (!(s & k)) (dp[i][s] += dp[i - 1][k]) %= mod;
        }
      }
    }
  }
  for (int s = 0; s < 1 << n; s++) {
    (ans += dp[m][s]) %= mod;
  }
  printf("%d\n", ans);
  return 0;
}