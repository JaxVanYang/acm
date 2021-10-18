#include <iostream>
using namespace std;

template<typename T> void read(T &t) {
    t = 0;
    int k = -1;
    char ch = getchar();
    while (ch <= ' ') {
        ch = getchar();
    }
    if (ch == '-') {
        k = 1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        t = t * 10 - ch + '0';
        ch = getchar();
    }
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t), read(args...);
}

int main() {
    int t;
    read(t);

    while (t--) {
        int a, b, c, d;
        read(a, b, c, d);

        if (b * d >= 0) {
            puts("1");
        } else {
            puts("0");
        }
    }
}