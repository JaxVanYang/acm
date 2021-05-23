#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
char m[2][maxn];

int main() {
    int n, k;
    cin >> n >> k;

    printf("YES\n");
    auto line = [&]() {
        for (int i = 0; i < n; ++i) putchar('.');
        putchar('\n');
    };
    line();

    char mid1 = '.', mid2 = '.';
    int h1, h2;
    int tot = (n - 2) * 2;
    if (k == tot) { mid1 = mid2 = '#'; k -= 2; }
    else if (k & 1) mid1 = '#', k -= 1;
    if (k <= n - 3) h1 = k / 2, h2 = 0;
    else h1 = (n - 3) / 2, h2 = (k - n + 3) / 2;
    int half = (n - 3) / 2;

    auto hotel = [&](int h, char mid) {
        putchar('.');
        for (int i = 0; i < h; ++i) putchar('#');
        for (int i = 0; i < half - h; ++i) putchar('.');
        putchar(mid);
        for (int i = 0; i < half - h; ++i) putchar('.');
        for (int i = 0; i < h; ++i) putchar('#');
        printf(".\n");
    };

    hotel(h1, mid1);
    hotel(h2, mid2);

    line();
    int tmp = n - 2;
}
/* 
 * 可以通过对称性来解决
 */