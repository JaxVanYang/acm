#include <iostream>
using namespace std;

const int maxn = 55;

int matrix[maxn][maxn];
int n;

bool check(int row, int col) {
    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        for (int j = 0; j < n; ++j) {
            if (j == col) continue;
            if (matrix[i][col] + matrix[row][j] == matrix[row][col]) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", matrix[i] + j);
        }
    }
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (matrix[row][col] != 1 && !check(row, col)) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
}