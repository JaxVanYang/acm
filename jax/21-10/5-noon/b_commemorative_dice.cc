#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[6], b[6];

    for (int i = 0; i < 6; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < 6; ++i) {
        scanf("%d", b + i);
    }

    int cnt = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (a[i] > b[j]) {
                ++cnt;
            }
        }
    }

    int g = __gcd(cnt, 36);
    printf("%d/%d\n", cnt / g, 36 / g);
}