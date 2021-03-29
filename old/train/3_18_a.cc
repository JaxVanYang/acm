#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], t[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", t + i);

    int ans = 0, cur = 0;
    for (int i = 1; i <= k; ++i) cur += a[i];
    for (int i = k + 1; i <= n; ++i) if (t[i]) cur += a[i];
    ans = cur;
    for (int i = 2; i + k - 1 <= n; ++i) {
        if (!t[i - 1]) cur -= a[i - 1];
        if (!t[i + k - 1]) cur += a[i + k - 1];
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
}