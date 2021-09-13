#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int cnt[N][N][11];
int sum[N][N][11];

int main() {
    int n, q, c;
    cin >> n >> q >> c;

    for (int i = 0; i < n; ++i) {
        int x, y, s;
        cin >> x >> y >> s;
        cnt[x][y][s]++;
    }

    for (int s = 0; s <= c; ++s) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                sum[i][j][s] = sum[i - 1][j][s] + sum[i][j - 1][s] - sum[i - 1][j - 1][s] + cnt[i][j][s];
            }
        }
    }

    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;

        for (int s = 0; s <= c; ++s) {
            int val = (t + s) % (c + 1);

            int t = sum[x2][y2][s] + sum[x1 - 1][y1 - 1][s] - sum[x1 - 1][y2][s] - sum[x2][y1 - 1][s];

            // cout << "val = " << val << " t = " << t << endl;

            ans += val * t;
        }

        cout << ans << endl;
    }
}