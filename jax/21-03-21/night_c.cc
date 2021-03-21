#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        tot += a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (2 * sum >= tot) {
            printf("%d", i);
            return 0;
        }
    }
}