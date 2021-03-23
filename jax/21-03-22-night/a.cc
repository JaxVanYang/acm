#include <iostream>
using namespace std;
const int maxn = 1005;
int arr[maxn];

int main() {
    int n, a, b, c, t;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &t);
    for (int i = 0; i < n; ++i) scanf("%d", arr + i);
    int ans = n * a;
    int k = c - b;
    if (k > 0) {
        for (int i = 0; i < n; ++i) ans += (t - arr[i]) * k;
    }
    printf("%d", ans);
}