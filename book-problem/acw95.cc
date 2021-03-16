#include <iostream>
#include <cstring>
using namespace std;
int grid[10][10], cpy[10][10];  // 有效位从 1 到 5
int dr[] = {0, 0, 1, 0};
int dc[] = {1, -1, 0, 0};
void change(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int r_ = r + dr[i], c_ = c + dc[i];
        cpy[r_][c_] = !cpy[r_][c_];
    }
}

int calc() {
    int ret = 0x3f3f3f3f;   // 初始化返回步数无穷大
    for (int mask = 0; mask < 1 << 5; ++mask) { // 穷举二进制代码
        memcpy(cpy, grid, sizeof(grid));    // 每次操作都在 cpy 上进行，不改变 grid
        int cnt = 0;
        for (int i = 0; i < 5; ++i) {   // 如果第 i 位 为 1 就变换 [1][i + 1]
            if ((mask >> i) & 1) {
                ++cnt;
                change(1, i + 1);
            }
        }
        
        for (int i = 1; i <= 4; ++i) {    // 从 1 到 4 递推下一行
            for (int j = 1; j <= 5; ++j) if (cpy[i][j] == 0) {  // 如果这个灯是关的，就变换下面的灯
                change(i + 1, j);
                ++cnt;
            }
        }
        bool flag = false;
        // 如果最后一行有关闭的就跳过
        for (int i = 1; i <= 5; ++i) if (cpy[5][i] == 0) { flag = true; break; }
        if (flag) continue;
        ret = min(ret, cnt);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    char s[7];
    while (n--) {
        for (int i = 1; i <= 5; ++i) {
            scanf("%s", s);
            for (int j = 0; j < 5; ++j) {
                grid[i][j + 1] = s[j] - '0';
            }
        }
        int ans = calc();
        if (ans > 6) printf("-1\n");
        else printf("%d\n", ans);
    }
}