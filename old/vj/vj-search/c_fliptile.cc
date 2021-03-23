#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> flip;
vector<vector<int>> ans;
vector<vector<int>> cpy;
int m, n;

int moves[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool dfs(int row, int col) {
    return true;
}

int main() {
    cin >> m >> n;
    grid.assign(m, vector<int>(n));
    ans.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    cpy.assign(m, vector<int>(n));

    int minCnt = 0x3f3f3f3f;

    for (int mask = 0; mask < 1 << n; ++mask) {
        int cnt = 0;
        flip.assign(m, vector<int>(n, 0));
        // auto cpy(grid);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cpy[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (mask & 1 << i) {
                int col = n - 1 - i;
                ++cnt;
                flip[0][col] = 1;
                for (int j = 0; j < 5; ++j) {
                    int r = moves[j][0], c = col + moves[j][1];
                    if (0 <= r && r < m && 0 <= c && c < n) {
                        cpy[r][c] = !cpy[r][c];
                    }
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cpy[i - 1][j]) {
                    flip[i][j] = 1;
                    ++cnt;
                    for (int k = 0; k < 5; ++k) {
                        int r = i + moves[k][0], c = j + moves[k][1];
                        if (0 <= r && r < m && 0 <= c && c < n) {
                            cpy[r][c] = !cpy[r][c];
                        }
                    }
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (cpy[m - 1][i]) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        if (cnt < minCnt) {
            minCnt = cnt;
            // ans = flip;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans[i][j] = flip[i][j];
                }
            }
        }
    }

    if (minCnt == 0x3f3f3f3f) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < m; ++i) {
            printf("%d", ans[i][0]);
            for (int j = 1; j < n; ++j) {
                printf(" %d", ans[i][j]);
            }
            putchar('\n');
        }
    }
}