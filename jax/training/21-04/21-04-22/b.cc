#include <iostream>
using namespace std;

int main() {
    int n, m;   // m for 0, n for 1
    cin >> m >> n;
    if (n > 2 * (m + 1) || n < m - 1) {
        puts("-1");
        return 0;
    }
    if (n == m - 1) {
        printf("0");
        for (int i = 0; i < n; ++i) {
            printf("10");
        }
    } else if (n <= 2 * m) {
        printf("0");
        for (int i = 1; i < m; ++i) {
            putchar('1');
            if (n - (m - i) > 1) {
                putchar('1');
                n -= 2;
            } else {
                n -= 1;
            }
            putchar('0');
        }
        for (int i = 0; i < n; ++i) {
            putchar('1');
        }
    } else {
        for (int i = 0; i < m; ++i) {
            printf("110");
        }
        for (int i = 0; i < n - 2 * m; ++i) {
            putchar('1');
        }
    }
}