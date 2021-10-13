// 弄清楚循环的是哪一部分，以及能否覆盖到所有的数
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 105;
int a[maxn];
int cnts[maxn], b[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(cnts, 0, sizeof(cnts));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if (!cnts[a[i]]) {
                ++cnt;
            }
            ++cnts[a[i]];
        }
        if (cnt > k) {
            puts("-1");
            continue;
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnts[i]) {
                b[cnt++] = i;
            }
        }
        for (int i = cnt; i < k; ++i) {
            b[i] = b[i % cnt];
        }
        printf("%d\n", k * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                printf("%d ", b[j]);
            }
        }
        puts("");
    }
}