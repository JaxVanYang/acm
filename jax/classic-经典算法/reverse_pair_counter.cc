#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 100;
int a[maxn], b[maxn];

void count(int a[], int l, int r, ll &cnt) {
    if (l >= r) return;
    int mid = l + r >> 1;
    count(a, l, mid, cnt);
    count(a, mid + 1, r, cnt);
    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[p++] = a[i++];
        else {
            // cout << "reverse" << endl;
            /* 
             * 原理是找出所有这样的逆序对：（i，j），其中 i 属于左区间，j 属于右区间
             * 因为归并排序的分区可以覆盖所有的情况，所以可行
             */
            cnt += mid - i + 1;
            b[p++] = a[j++];
        }
    }
    while (i <= mid) b[p++] = a[i++];
    while (j <= r) b[p++] = a[j++];
    for (int i = l; i <= r; ++i) a[i] = b[i];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    ll ans = 0;
    count(a, 0, n - 1, ans);
    printf("%lld\n", ans);
    // for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}