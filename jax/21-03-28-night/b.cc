#include <iostream>
using namespace std;
const int maxn = 105;
char a[maxn][maxn];
int n, m;
bool check(int r, int c) {
    int cnt = 0;
    for (int i = -1; i <= 1; ++i) {
        int row = r + i;
        if (row < 0 || row >= n) continue;
        for (int j = -1; j <= 1; ++j) {
            int col = c + j;
            if (col < 0 || col >= m) continue;
            cnt += a[row][col] == '*';
        }
    }
    int ans = a[r][c] == '.' ? 0 : a[r][c] - '0';
    return cnt == ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%s", &a[i][0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '*' && !check(i, j)) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}