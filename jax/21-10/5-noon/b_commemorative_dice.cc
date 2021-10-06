#include <iostream>
#include <cctype>

template<typename T>
void read(T &x) {
    x = 0;

    int k = 1;

    char ch = getchar();

    if (ch == '-') {
        k = -1;
        ch = getchar();
    }

    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    x *= k;
}

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 6;

int main() {
    int a[N], b[N];

    for (int i = 0; i < N; ++i) {
        read(a[i]);
    }

    for (int i = 0; i < N; ++i) {
        read(b[i]);
    }

    int c = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i] > b[j]) {
                ++c;
            }
        }
    }

    int g = gcd(c, 36);
    printf("%d/%d\n", c / g, 36 / g);
}