#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include<bits/stdc++.h>
using namespace std;

#define sfi(i) scanf("%d", &i)
#define sfs(i) scanf("%s", (i))
#define pri(i) printf("%d\n", i)
#define sff(i) scanf("%lf", &i)
#define ll long long
#define ull unsigned long long
#define mem(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f
#define eps 1e-16
#define PI acos(-1)
#define lowbit(x) ((x) & (-x))
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)
#define fl() printf("flag\n")
#define MOD(x) ((x % mod) + mod) % mod
#define endl '\n'
#define pb push_back
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0)

const int maxn = 1e6 + 9;
const int mod = 1e4 + 7;

inline ll read() {
  ll f = 1, x = 0;
  char ss = getchar();
  while (ss < '0' || ss > '9') {
    if (ss == '-') f = -1;
    ss = getchar();
  }
  while (ss >= '0' && ss <= '9') {
    x = x * 10 + ss - '0';
    ss = getchar();
  }
  return f * x;
}

int dp[2009][2009];
int a[2009];
int main() {
  int n;
  while (cin >> n && n) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i + n] = a[i];
    mem(dp, 0);
    for (int i = 1; i <= 2 * n; i++) dp[i][i] = 1;
    for (int len = 2; len <= 2 * n; len++)  //区间长度
    {
      for (int i = 1; i + len - 1 <= 2 * n; i++)  //区间起点
      {
        int j = i + len - 1;  //区间终点
        if (a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
        dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[i][i + n - 1]);
      ans = max(ans, dp[i][i + n] - 1);  //有不同起点区间
    }
    printf("%d\n", ans);
  }

  return 0;
}