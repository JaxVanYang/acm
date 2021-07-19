#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n;

inline bool cmp(int a, int b) {
    return a > b;
}

int calc(int arr[], int size) {
    if (size <= 0) return 0;
    if (size > n) return arr[n];
    return arr[size];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
    }

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);

    for (int i = 2; i <= n; ++i) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        int stage_size = mid + n;
        int selected_size = stage_size - stage_size / 4;
        int sa = calc(a, selected_size - mid);
        if (selected_size <= mid) sa += 100 * selected_size;
        else sa += 100 * mid;
        int sb = calc(b, selected_size);

        if (sa < sb) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}