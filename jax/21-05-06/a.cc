#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, v;
    scanf("%d%d", &n, &v);
    int ans = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        int need = n - i;
        if (need <= v) {
            ans += i * (need - now);
            printf("%d\n", ans);
            return 0;
        }
        ans += i * (v - now);
        now = v - 1;
    }
    printf("%d\n", ans);
}