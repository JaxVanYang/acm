// 打表代码，过题代码在最下方注释里

#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e3 + 1;
char table[N + 5][N + 5];

int main() {
    memset(table, 'x', sizeof(table));
    
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            table[i][j] = table[j][i] = 'a';
        }
    }
    table[2][3] = 'b';
    table[3][2] = 'b';
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (table[i][j] == 'x') table[i][j] = 'b';
            if (table[i][j] == 'b') {
                for (int x = 1; x < N; ++x) {
                    for (int y = 0; y < N; y += x) {
                        if (i + x < N && j + y < N) table[i + x][j + y] = 'a';
                        if (i + y < N && j + x < N) table[i + y][j + x] = 'a';
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            if (table[i][j] == 'b') {
                printf("\tst[%d][%d] = true;\n", i, j);
            }
        }
    }
}

// 过题代码
// const int N = 5005;
// bool st[N][N];

// void init() {
//    // 此处替换为打表数据
// }

// int main() {
//     init();
//     int t;
//     scanf("%d", &t);
//     while (t--) {
//         int n, m;
//         scanf("%d%d", &n, &m);
//         if (n > m) swap(n, m);
//         if (st[n][m]) puts("Bob");
//         else puts("Alice");
//     }
// }