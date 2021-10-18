#include <iostream>
#include <cctype>
using namespace std;
using ll = long long;

template<typename T> void read(T &t) {
    t = 0;
    int k = 1;
    char ch = getchar();
    if (ch == '-') {
        k = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t), read(args...);
}

const int N = 1e5 + 10, mod = 1e9 + 7;
int a[N], f[N];

inline int add(int a, int b) {
    return (a + b) % mod;
}
template<typename ...Args> int add(int a, int b, Args ...args) {
    return add(add(a, b), args...);
}
inline int mul(int a, int b) {
    return (ll)a * b % mod;
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; ++i) {
        read(a[i]);
    }

    f[0] = a[0];
    for (int i = 1; i < n; ++i) {
        f[i] = add(f[i - 1], mul(f[i - 1], a[i]), a[i]);
    }

    printf("%d\n", f[n - 1]);
}