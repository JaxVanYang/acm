#include <iostream>
using namespace std;

const int N = 2010;
char grid[N][N];
bool u[N][N], d[N][N], l[N][N], r[N][N];
int row[N], col[N];
int ver[N][N], hor[N][N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%s", grid[i] + 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (grid[i][j] == 'B') {
                u[i][j] = l[i][j] = true;
            } else {
                u[i][j] = u[i - 1][j];
                l[i][j] = l[i][j - 1];
            }
            // cout << u[i][j] << ' ';
        }
        // cout << endl;
    }

    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            if (grid[i][j] == 'B') {
                d[i][j] = r[i][j] = true;
            } else {
                d[i][j] = d[i + 1][j];
                r[i][j] = r[i][j + 1];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!r[i][1]) {
            row[i] = 1;
        }

        if (!d[1][i]) {
            col[i] = 1;
        }
    }

    for (int i = 1; i <= n - k + 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!col[j] && !u[i - 1][j] && !d[i + k][j]) {
                ver[i][j] = 1;
            }

            if (!row[j] && !l[j][i - 1] && !r[j][i + k]) {
                hor[j][i] = 1;
            }

            ver[i][j] += ver[i][j - 1];
            hor[j][i] += hor[j - 1][i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        row[i] += row[i - 1];
        col[i] += col[i - 1];
    }

    for (int i = 1; i <= n - k + 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            // cout << ver[i][j] << ' ';
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - k + 1; ++j) {
            // cout << ver[i][j] << ' ';
        }
        // cout << endl;
    }

    int ans = 0;

    int sum = row[n] + col[n];

    for (int i = 1; i <= n - k + 1; ++i) {
        for (int j = 1; j <= n - k + 1; ++j) {
            int tmp = sum
                        + ver[i][j + k - 1] - ver[i][j - 1]
                        + hor[i + k - 1][j] - hor[i - 1][j];
            // cout << "i = " << i << " j = " << j << " tmp = " << tmp << endl;
            // cout << "row = " << row[j + k - 1] - row[j - 1] << endl
                //  << "col = " << col[i + k - 1] - col[i - 1] << endl
                //  << "ver = " << ver[i][j + k - 1] - ver[i][j - 1] << endl
                //  << "hor = " << hor[i + k - 1][j] - hor[i - 1][j] << endl;
            ans = max(ans, tmp);
        }
    }

    printf("%d\n", ans);
}