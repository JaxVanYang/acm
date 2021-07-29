#include <iostream>
using namespace std;

const int N = 3e5 + 10;

int q[N], l = 1, r = 1;
int sum[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", sum + i);
        sum[i] += sum[i - 1];
    }

    // Note: 在使用前重置队列
    q[1] = 0, l = 1, r = 1;
    int ans = INT32_MIN;
    for (int i = 1; i <= n; ++i) {
        while (l <= r && q[l] < i - m) ++l;
        ans = max(ans, sum[i] - sum[q[l]]);
        while (l <= r && sum[q[r]] >= sum[i]) --r;
        q[++r] = i;
    }
    printf("%d\n", ans);
}