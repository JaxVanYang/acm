#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    a[n++] = 2e9;
    int r = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        while (r < n && a[i] >= a[r]) ++r;
        if (a[i] < a[r] - k) {
            ans++;
        }
    }
    printf("%d\n", ans);
}