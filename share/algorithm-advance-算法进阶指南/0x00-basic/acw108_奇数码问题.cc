// MLE code

#include <iostream>
using namespace std;
const int maxn = 250005;
int a[maxn], b[maxn], tmp[maxn];
int cnt;

void merge(int a[], int l, int r) {
    if (l >= r) return;
    int mid = l + (l + r) / 2;
    // int ret = merge(a, l, mid) + merge(a, mid + 1, r);
    merge(a, l, mid);
    merge(a, mid + 1, r);
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
    for (int i = l; i <= r; ++i) a[i] = tmp[i];
    // return ret;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int p = 0, lmt = n * n;
        for (int i = 0; i < lmt; ++i) {
            scanf("%d", a + i);
            if (a[i]) ++p;
        }
        p = 0;
        for (int i = 0; i < lmt; ++i) {
            scanf("%d", b + i);
            if (b[i]) ++p;
        }
        // int cnt1 = merge(a, 0, n - 1), cnt2 = merge(b, 0, n - 1);
        cnt = 0;
        merge(a, 0, n - 1);
        int cnt1 = cnt;
        cnt = 0;
        merge(b, 0, n - 1);
        int cnt2 = cnt;
        if ((cnt1 & 1) == (cnt2 & 1)) {
            printf("TAK\n");
        } else printf("NIE\n");
    }
}