#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];

int main() {
    // Note: position is 1-index
    int n, k, len, m;
    scanf("%d%d%d%d", &n, &k, &len, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", a + i);
    }

    if ((n + 1) / (len + 1) < k) {
        puts("0");
        return 0;
    }

    int l = 0, r = m;

    auto check = [&](int pos) {
        memcpy(b, a, sizeof(int) * (pos + 1));
        sort(b, b + pos + 1);
        int last = 0;
        int cnt = 0;
        for (int i = 0; i <= pos; ++i) {
            cnt += (b[i] - last) / (len + 1);
            last = b[i];
        }
        // Note: consider boundary
        cnt += (n + 1 - last) / (len + 1);
        return cnt >= k;
    };

    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l == m) {
        puts("-1");
    } else {
        printf("%d\n", l + 1);
    }
}