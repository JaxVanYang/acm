#include <iostream>
using namespace std;

const int N = 250010;
int a[N], b[N];
int c[N];

int count(int arr[], int l, int r) {
  if (l >= r) return 0;
  int ret = 0;
  int mid = l + r >> 1;

  // Trick：因为只需要判断奇偶型，所以可以使用异或代替加减法，并且可以不用担心溢出
  ret ^= count(arr, l, mid);
  ret ^= count(arr, mid + 1, r);

  int x = l, y = mid + 1;
  for (int i = l; i <= r; ++i) {
    if (y > r || x <= mid && arr[x] < arr[y]) {
      c[i] = arr[x++];
    } else {
      ret ^= mid - x + 1;
      c[i] = arr[y++];
    }
  }
  for (int i = l; i <= r; ++i) {
    arr[i] = c[i];
  }
  return ret;
}

int main() {
  int n;
  while (EOF != scanf("%d", &n)) {
    int len = n * n;
    for (int i = 0, p = 0; i < len; ++i) {
      int x;
      scanf("%d", &x);
      if (x) a[p++] = x;
    }
    for (int i = 0, p = 0; i < len; ++i) {
      int x;
      scanf("%d", &x);
      if (x) b[p++] = x;
    }
    int a_cnt = count(a, 0, len - 1);
    int b_cnt = count(b, 0, len - 1);
    if ((a_cnt - b_cnt) & 1) {
      puts("NIE");
    } else {
      puts("TAK");
    }
  }
}