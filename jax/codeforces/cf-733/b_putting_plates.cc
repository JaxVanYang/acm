#include <iostream>
#include <cstring>
using namespace std;

const int N = 22;
char table[N][N];

void solve() {
    memset(table, '0', sizeof(table));
    int h, w;
    scanf("%d%d", &h, &w);
    table[1][1] = table[h][1] = table[1][w] = table[h][w] = '1';
    for (int i = 3; i < h - 1; i += 2) {
        table[i][1] = table[i][w] = '1';
    }
    for (int i = 3; i < w - 1; i += 2) {
        table[1][i] = table[h][i] = '1';
    }
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            putchar(table[i][j]);
        }
        puts("");
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}