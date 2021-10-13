#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10, M = 1e7 + 10;

pair<pair<int, int>, int> ps[M];
int dp[N];
int tot = 0;
int a, t;

int main() {
    scanf("%d%d", &a, &t);

    for (int i = 0; i < a; ++i) {
        int h, d, t;
        scanf("%d%d%d", &h, &d, &t);

        for (int j = 0; j < t; ++j) {
            int b;
            scanf("%d", &b);

            ps[tot++] = {{b, b + d}, h};        
        }
    }

    sort(ps, ps + tot);

    int p = 0, maxV = 0;
    for (int i = 0; i < t; ++i) {
        maxV = max(maxV, dp[i]);

        while (p < tot && ps[p].first.first == i) {
            int ed = ps[p].first.second;

            if (ed < t) {
                dp[ed] = max(dp[ed], maxV + ps[p].second);
            } else {
                dp[t] = max(dp[t], maxV + ps[p].second);
            }

            ++p;
        }
    }

    printf("%d\n", max(maxV, dp[t]));
}