#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

int h[100005][15];

int main() {
  int a, b, c, d;
  while (~scanf("%d", &a) && a) {
    int ans = 0;
    memset(h, 0, sizeof(h));
    for (b = 1; b <= a; b++) {
      scanf("%d %d", &c, &d);
      h[d][c]++;
      if (d > ans) ans = d;
    }
    for (b = ans - 1; b >= 0; b--) {
      for (c = 0; c <= 10; c++) {
        if (c == 0) {
          h[b][c] += max(h[b + 1][c], h[b + 1][c + 1]);
        } else if (c == 10) {
          h[b][c] += max(h[b + 1][c], h[b + 1][c - 1]);
        } else {
          h[b][c] += max(max(h[b + 1][c], h[b + 1][c + 1]), h[b + 1][c - 1]);
        }
      }
    }
    printf("%d\n", h[0][5]);
  }
  return 0;
}