#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 50;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}