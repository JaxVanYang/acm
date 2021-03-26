#include <iostream>
#include <cstring>
using namespace std;
int dp[25][25];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        string a, b;
        cin >> a >> b;
        int ans = 0;
        int len1 = a.length(), len2 = b.length();
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << len1 + len2 - 2 * ans << endl;
    }
}

