#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 100;

int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + 2 * n);
    printf("%lld\n", (ll)(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]));
}