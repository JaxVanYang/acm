// 暴力枚举

#include <iostream>
#include <cstring>

const int N = 5;
char grid[N][N];
char cpy[N][N];

void change(int mask) {
    memcpy(cpy, grid, sizeof(cpy));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (mask & 1) {
                for (int k = 0; k < 4; ++k) {
                    cpy[i][k] = cpy[i][k] == '+' ? '-' : '+';
                    if (k != i)
                        cpy[k][j] = cpy[k][j] == '+' ? '-' : '+';
                }
            }
            mask >>= 1;
        }
    }
}

bool check() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) 
            if (cpy[i][j] == '+') 
                return false;
    return true;
}

inline int lowbit(int num) {
    return num & -num;
}

inline int calc(int num) {
    int ret = 0;
    while (num) {
        ++ret;
        num -= lowbit(num);
    }
    return ret;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        scanf("%s", grid[i]);
    }

    int ans = -1, cnt = 1000;
    for (int i = 1; i < (1 << 16); ++i) {
        change(i);
        if (check() && calc(i) < cnt) {
            ans = i;
            cnt = calc(i);
        }
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (ans & 1) printf("%d %d\n", i, j);
            ans >>= 1;
        }
    }

}