#include <iostream>
using namespace std;

bool dp[55][1005];

int main() {
    int n, x, ma;
    scanf("%d%d%d", &n, &x, &ma);
    dp[0][x] = true;
    for (int i = 1; i <= n; ++i) {
        int c;
        scanf("%d", &c);
        for (int j = 0; j <= ma; ++j) if (dp[i - 1][j]) {
            if (j + c <= ma) dp[i][j + c] = true;
            if (j - c >= 0) dp[i][j - c] = true;
        }
    }
    for (int val = ma; val >= 0; --val) if (dp[n][val]) {
        printf("%d\n", val);
        return 0;
    }
    puts("-1");
}