#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define debug(x) cout << #x << ":" << x << endl;
#define bug cout << "********" << endl;
#define all(x) x.begin(), x.end()
#define lowbit(x) x & -x
#define fin(x) freopen(x, "r", stdin)
#define fout(x) freopen(x, "w", stdout)
#define ull unsigned long long
#define ll long long

const double eps = 1e-15;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

using namespace std;

int n, s[maxn], dp1[maxn], dp2[maxn];
char p[maxn];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", p + 1);
    n = strlen(p + 1);
    for (int i = 0; i <= n + 1; i++) dp1[i] = dp2[i] = inf;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (p[i] == 'B' ? 1 : -1);
    for (int i = 1; i <= n; i++) dp1[i] = min(dp1[i - 1], s[i]);
    for (int i = n; i >= 1; i--) dp2[i] = min(dp2[i + 1], s[i]);

    if (dp1[n] >= 0) {
      puts("0");
      continue;
    }
    int ok = 1;
    for (int i = 1; i < n; i++) {
      int a = dp1[i], b = dp2[i + 1];
      if (b - s[i] >= 0) {
        if (a + s[n] - s[i] >= 0) {
          printf("%d\n", i);
          ok = 0;
          break;
        }
      }
    }
    if (ok) puts("-1");
  }
  return 0;
}