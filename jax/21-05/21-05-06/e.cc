#include <iostream>
using namespace std;

const int maxn = 5050;
int l[maxn], r[maxn], cnt[maxn], pre[maxn];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", l + i, r + i);
        for (int j = l[i]; j <= r[i]; ++j) {
            ++cnt[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < q - 1; ++i) {
        for (int j = l[i]; j <= r[i]; ++j) {
            --cnt[j];
        }
        int sum = 0;
        for (int j = 1; j <= n; ++j) sum += cnt[j] > 0 ? 1 : 0;
        for (int j = 1; j <= n; ++j) {
            // Note：注意运算优先级，加括号
            pre[j] = pre[j - 1] + (cnt[j] == 1 ? 1 : 0);
        }
        for (int j = i + 1; j < q; ++j) {
            ans = max(ans, sum - pre[r[j]] + pre[l[j] - 1]);
        }
        for (int j = l[i]; j <= r[i]; ++j) {
            ++cnt[j];
        }
    }
    printf("%d\n", ans);
}