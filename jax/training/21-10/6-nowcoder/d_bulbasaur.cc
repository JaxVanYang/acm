#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
pair<int, int> ps[N];
int candi[N];

template<typename T>
void read(T &t) {
    t = 0; int k = 1;
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
template<typename T, typename ...Args>
void read(T &t, Args &...args) {
    read(t), read(args...);
}

void solve() {
    int n, m, k;
    read(n, m, k);
    fill(candi + 1, candi + m + 1, 0);

    for (int i = 0; i < k; ++i) {
        int a, b, c;
        read(a, b, c);
        candi[b] = max(candi[b], c);
    }

    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans += candi[i];
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    read(t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
}