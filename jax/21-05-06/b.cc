// Note: You can modify at most once!

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxn = 5e4 + 5;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int minV = *min_element(a, a + n);
    int sum = accumulate(a, a + n, 0);
    int ans = sum;
    for (int i = 0; i < n; ++i) {
        for (int d = 2; d * d <= a[i]; ++d) {
            if (a[i] % d != 0) continue;
            int cur = sum - minV - a[i];
            cur += minV * d + a[i] / d;
            ans = min(ans, cur);
        }
    }
    printf("%d\n", ans);
}