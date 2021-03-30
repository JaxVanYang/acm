#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

const int maxn = 1e6 + 5;
int pres[][3] = {{1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7}, {0, 5, 6}, {1, 4, 7}, {2, 4, 7}, {3, 5, 6}};
int dp[2][8];
// int dp[maxn][8];

int main() {
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        // int pre = (i ^ 1) & 1, now = i & 1;
        int now = i & 1, pre = now ^ 1;
        // int pre = i - 1, now = i;
        // cout << "pre = " << pre << " now = " << now << endl;
        for (int j = 0; j < 8; ++j) dp[now][j] = 0;
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[now][j] = (dp[now][j] + dp[pre][pres[j][k]]) % mod;
            }
        }
    }
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j < 8; ++j) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    cout << dp[n & 1][0] << endl;
    // cout << dp[n][0] << endl;
}