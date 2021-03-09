#include <bits/stdc++.h>
using namespace std;
#define N 200005
int a[N], f[N], n, t, k, dis;
int main() {
  scanf("%d%d%d", &n, &t, &k);
  for (int i = 1; i <= t; i++) scanf("%d", &a[i]);
  a[0] = ((k > n - t) ? 2 : 1);
  for (int i = 0; i <= t; i++) {
    f[i] = min(a[i], a[i + 1]);
    k -= a[i] - f[i];
  }
  if (k < 0 || a[0] > 1) {
    puts("-1");
    return 0;
  }
  for (int i = t - 1; i > 0; i--) {
    int p = min(f[i] - 1, k);
    k -= p;
    f[i] -= p;
  }
  printf("%d\n", n);
  dis = 1;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < a[i]; j++)
      printf("%d %d\n", dis + j % f[i - 1], dis + a[i - 1] + j);
    dis += a[i - 1];
  }
  return 0;
}