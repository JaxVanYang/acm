#include <bits/stdc++.h>
using namespace std;

const int N = 14, M = (1 << N) + 10;
set<int> sets[M];
int wins[M];

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

void reset(int n) {
    for (int i = 1; i <= n; ++i) {
        sets[i].clear();
        wins[i] = i;
    }
}

void solve() {
    int n;
    read(n);
    const int m = 1 << n;
    reset(m);

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            read(val);
            sets[i].insert(val);
        }
    }

    for (int range = n; range; --range) {
        for (int i = 1; i <= (1 << (range - 1)); ++i) {
            int p = i << 1, q = p - 1;
            int u = wins[p], v = wins[q];
            int val1 = *sets[u].rbegin(), val2 = *sets[v].rbegin();

            if (val1 > val2) {
                sets[u].erase(sets[u].upper_bound(val2));
                wins[i] = u;
            } else {
                sets[v].erase(sets[v].upper_bound(val1));
                wins[i] = v;
            }
        }
    }

    printf("%d\n", wins[1]);
}

int main() {
    int t;
    read(t);

    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
}