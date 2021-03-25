#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
char m[2][maxn];

int main() {
    int n, k;
    cin >> n >> k;
    int p = 2 * (n - 2) - k;
    printf("YES\n");
    for (int i = 0; i < n; ++i) putchar('.');
    putchar('\n');
    int tmp = n - 2;

    if (k == 2 * tmp) {
        memset(m, '#', sizeof(m));
    } else {
        if (k & 1) {
            m[1][0] == '#';
        }
    }

    // if (k == 0) memset(m, '.', sizeof(m));
    // else {
    //     memset(m, '#', sizeof(m));
    //     int left = n - 2 - k;
    //     if (left & 1) m[1][tmp / 2] = '.', --left;
    //     if (left < tmp) for (int i = 0; i < left / 2; ++i) {
    //         m[0][i] = m[0][tmp - 1 - i] = '.';
    //     } else {
    //         for (int i = 0; i < tmp; ++i) m[0][i] = '.';
    //         left -= tmp;
    //         for (int i = 0; i < left / 2; ++i) m[1][i] = m[1][tmp - 1 - i] = '.';
    //     }
    // }

    // int size;
    // if (k >= n - 2) {
    //     if (k & 1) {
    //         size = n - 2;
    //         k -= n - 2;
    //     } else {
    //         size = n - 2 - 1;
    //         k -= n - 2 - 1;
    //     }
    // } else {
    //     if (k & 1) 
    // }

    // putchar('.');
    // int size = min(n - 2, k);
    // for (int i = 0; i < size; ++i) putchar('#');
    // for (int i = 0; i < n - 2 - size; ++i) putchar('.');
    // cout << "." << endl;
    
    // putchar('.');
    // if (k > n - 2) size = k - n + 2;
    // else size = 0;
    // for (int i = 0; i < size; ++i) putchar('#');
    // for (int i = 0; i < n - 2 - size; ++i) putchar('.');
    // cout << "." << endl;

    for (int i = 0; i < 2; ++i) {
        putchar('.');
        for (int j = 0; j < tmp; ++j) printf("%c", m[i][j]);
        printf(".\n");
    }


    for (int i = 0; i < n; ++i) putchar('.');
    putchar('\n');

}