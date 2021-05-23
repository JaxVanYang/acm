#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn];

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (a[i] <= x) {
            ++cnt;
        }
    }
    if (x > y) {
        printf("%d\n", n);
    } else {
        printf("%d\n", (cnt + 1) / 2);
    }
}