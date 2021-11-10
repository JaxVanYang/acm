#include <iostream>
#include <cstring>

const int N = 1e6 + 10;
char s[N];
int dx[128], dy[128];

void init() {
    dx['L'] = -1;
    dx['R'] = 1;
    dy['U'] = -1;
    dy['D'] = 1;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    int len = strlen(s);

    int l = 0, r = 0, u = 0, d = 0;
    int x = 0, y = 0;
    for (int i = 0; i < len; ++i) {
        int x_ = x + dx[s[i]], y_ = y + dy[s[i]];
        int l_ = std::min(x_, l), r_ = std::max(x_, r);
        int u_ = std::max(u, y_), d_ = std::min(d, y_);
        if (r_ - l_ + 1 > m || u_ - d_ + 1 > n) {
            break;
        }
        l = l_, r = r_, u = u_, d = d_;
        x = x_, y = y_;
    }

    printf("%d %d\n", 1 - d, 1 - l);
}

int main() {
    init();

    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}