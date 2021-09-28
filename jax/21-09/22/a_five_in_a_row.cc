#include <iostream>
using namespace std;

char grid[11][11];
int dx[4] = {1, 0, 1, 1};
int dy[4] = {0, 1, 1, -1};

bool valid(int x, int y) {
    return 0 <= x && x <= 10 && 0 <= y && y <= 10;
}

bool check(int i, int j) {
    for (int k = 0; k < 4; ++k) {
        int l = 0, r = 0;

        while (valid(i + dx[k] * l, j + dy[k] * l) && grid[i + dx[k] * l][j + dy[k] * l] == 'X') {
            --l;
        }
        while (valid(i + dx[k] * r, j + dy[k] * r) && grid[i + dx[k] * r][j + dy[k] * r] == 'X') {
            ++r;
        }

        if (r - l - 1 >= 5) {
            return true;
        }
    }

    return false;
}

int main() {

    for (int i = 0; i < 10; ++i) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'X';

                if (check(i, j)) {
                    puts("YES");
                    return 0;
                }

                grid[i][j] = '.';
            }
        }
    }

    puts("NO");
}