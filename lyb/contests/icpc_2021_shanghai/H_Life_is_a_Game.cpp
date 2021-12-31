#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vec vector
#define pb push_back
#define all(a) a.begin(), a.end()

int main() {
  ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vec<ll> a(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vec<tuple<ll, int, int>> edge(m);
  for (auto &[w, u, v] : edge) cin >> u >> v >> w;
  // build Kruskal Reconstruction Tree
  vec<vec<int>> G(n + 1);
  vec<int> p(n + 1, 0);
  vec<ll>  t(n + 1, 0);
  for (int i = 1; i <= n; i++) p[i] = i;
  function<int (int)> find = [&](const int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  };
  int rt = n;
  sort(all(edge));
  for (auto [w, u, v] : edge) {
    int pu = find(u), pv = find(v);
    if (pu == pv) continue;
    ++rt, p.pb(rt), a.pb(0), G.pb({pu, pv}), t.pb(w);
    p[pu] = p[pv] = rt; // union
    if (rt == n + n - 1) break;
  }
  // init rmq
  const int M = 20;
  vec<vec<int>> fa(rt + 1, vec<int>(M, 0));
  vec<vec<ll>> val(rt + 1,  vec<ll>(M, 0));
  function<void (int, int)> dfs = [&](int u, int f) {
    for (int v : G[u]) {
      if (v == f) continue;
      dfs(v, u);
      a[u] += a[v];
    }
    fa[u][0] = f, val[u][0] = t[f] - a[u];
  };
  dfs(rt, 0);
  for (int j = 1; j < M; j++)
    for (int i = 1; i <= rt; i++) {
      fa[i][j]  = fa[ fa[i][j - 1] ][j - 1];
      val[i][j] = max(val[i][j - 1], val[ fa[i][j - 1] ][j - 1]);
    }
  // answer Queries
  for (int x, k; q--; ) {
    cin >> x >> k;
    for (int j = M - 1; j >= 0; j--)
      if (fa[x][j] && val[x][j] <= k) x = fa[x][j];
    cout << (a[x] + k) << '\n';
  }
  return 0;
}
