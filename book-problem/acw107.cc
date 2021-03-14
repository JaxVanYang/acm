#include <iostream>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], tmp[maxn];
using ll = long long;
ll cnt;

void merge(int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            cnt += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l; i < k; ++i) a[i] = tmp[i];
}

int main() {
    int n;
    while (~(scanf("%d", &n))) {
        if (!n) return 0;
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        cnt = 0;
        merge(0, n - 1);
        printf("%lld\n", cnt);  // 注意 long long 的占位符是 %lld
    }
}