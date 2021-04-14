#include <iostream>
using namespace std;
const int maxn = 405;
char m[maxn][maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) scanf("%s", m[i]);
        int x1 = -1, y1 = -1, x2, y2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (m[i][j] == '*') {
                if (x1 == -1) {
                    x1 = i, y1 = j;
                } else {
                    x2 = i, y2 = j;
                    break;
                }
            }
        }
        if (x1 == x2) {
            if (x1 != 0) m[0][y1] = m[0][y2] = '*';
            else m[n - 1][y1] = m[n - 1][y2] = '*';
        } else if (y1 == y2) {
            if (y1 == 0) m[x1][n - 1] = m[x2][n - 1] = '*';
            else m[x1][0] = m[x2][0] = '*';
        } else {
            m[x1][y2] = m[x2][y1] = '*';
        }
        for (int i = 0; i < n; ++i) {
            printf("%s\n", m[i]);
        }
    }
}