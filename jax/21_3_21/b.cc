#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    int ans = maxn;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j] - a[i] <= k) ans = min(ans, n - j + i - 1);
        }
    }
    printf("%d\n", ans);
}