#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct node {
  int x;
  int y;
  int z;
} nod[105];

int dp[105];

int cmp(node a, node b) {
  if (a.x < b.x) return 1;
  if (a.x == b.x && a.y < b.y) return 1;
  return 0;
}

int main() {
  int n, cas = 1;
  while (cin >> n && n > 0) {
    int i, j, m = 0;
    int a[3];
    for (i = 0; i < n; i++) {
      cin >> a[0] >> a[1] >>
          a[2];  //每种有6种情况，但是由于x1<x2&&y1<y2可以缩减为3种情况
      nod[m].x = max(a[0], a[1]), nod[m].y = min(a[0], a[1]), nod[m++].z = a[2];
      nod[m].x = max(a[1], a[2]), nod[m].y = min(a[1], a[2]), nod[m++].z = a[0];
      nod[m].x = max(a[0], a[2]), nod[m].y = min(a[0], a[2]), nod[m++].z = a[1];
    }

    sort(nod, nod + m, cmp);
    for (i = 0; i < m; i++) {
      int ma = 0;
      for (j = 0; j < i; j++) {
        if (nod[j].x < nod[i].x && nod[j].y < nod[i].y) ma = max(ma, dp[j]);
      }
      dp[i] = ma + nod[i].z;
    }

    int res = 0;
    for (i = 0; i < m; i++) res = max(res, dp[i]);

    printf("Case %d: maximum height = %d\n", cas++, res);
  }
  return 0;
}