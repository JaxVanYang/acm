#include <iostream>
#include <algorithm>

const int N = 2e5 + 10;
int a[N], blue[N], red[N], len1, len2;

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    len1 = len2 = 0;
    char ch = getchar();
    for (int i = 1; i <= n; ++i) {
        ch = getchar();
        if (ch == 'B') {
            blue[++len1] = a[i];
        } else {
            red[++len2] = a[i];
        }
    }
    // std::cout << "len1 = " << len1 << " len2 = " << len2 << std::endl;

    std::sort(blue + 1, blue + len1 + 1);
    std::sort(red + 1, red + len2 + 1, std::greater<int>());
    for (int i = 1; i <= len1; ++i) {
        // std::cout << blue[i] << ' ';
        if (blue[i] < i) {
            puts("NO");
            return;
        }
    }
    for (int i = 1; i <= len2; ++i) {
        // std::cout << red[i] << ' ';
        if (red[i] > n - i + 1) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}