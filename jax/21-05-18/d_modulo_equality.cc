#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e3 + 100;
int a[maxn], b[maxn], c[maxn];

bool check(int n) {
    for (int i = 0; i < n; ++i) {
        if (b[i] != c[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    sort(b, b + n);
    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        int x = (m + b[0] - a[i]) % m;
        for (int j = 0; j < n; ++j) {
            c[j] = (a[j] + x) % m;
        }
        sort(c, c + n);
        if (check(n)) {
            ans = min(ans, x);
        }
    }
    printf("%d\n", ans);
}