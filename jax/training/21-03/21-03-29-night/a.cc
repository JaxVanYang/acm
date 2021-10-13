#include <iostream>
using namespace std;
const int maxn = 2005;
int cnts[maxn];
char grid[maxn][maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%s", &grid[i][0]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnts[j] += grid[i][j] == '1' ? 1 : 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            // cout << grid[i][j] << ' ';
            if (grid[i][j] == '1' && cnts[j] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
