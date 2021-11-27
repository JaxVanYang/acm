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
const int N   = 200 + 10;
const int inf = 0x3f3f3f3f;
const ll  INF = 1e18;
const db eps = 1e-8;

int T;

int n;
vec<int> G[N];
ll w[N], v[N], dp[N][N];

void dfs(int u, int fa) {
  for (int i = 1; i <= n; i++) dp[u][i] = v[i] - w[u];
  for (int v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
    for (int i = 0; i <= n; i++)
      dp[u][i] += max({dp[v][max(0, i - 1)], dp[v][i], dp[v][min(n, i + 1)]});
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v; G[u].pb(v), G[v].pb(u);
  }
  dfs(1, 0);
  cout << *max_element(dp[1], dp[1] + 1 + n);
  return 0;
}
