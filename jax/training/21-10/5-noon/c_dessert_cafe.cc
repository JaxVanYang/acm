#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int head[N], ver[M], nex[M], tot = 0;
bool mark[N], vis[N];

inline void add(int u, int v) {
    ver[++tot] = v;
    nex[tot] = head[u], head[u] = tot;
}

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

template<typename T, typename... Args>
void read(T &x, Args &...args) {
    read(x);
    read(args...);
}

template<typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }

    if (x > 9) {
        write(x / 10);
    }

    putchar(x % 10 + '0');
}

inline void nl() {
    putchar('\n');
}

bool dfs(int u, int pre) {
    bool ret = false;

    for (int i = head[u]; i; i = nex[i]) {
        int v = ver[i];

        if (v != pre && dfs(v, u)) {
            ret = true;
        }
    }

    if (ret || mark[u]) {
        return true;
    }

    vis[u] = true;
    return false;
}

int calc(int u) {
    if (vis[u]) {
        return 0;
    }

    vis[u] = true;

    int ret = 1;
    for (int i = head[u]; i; i = nex[i]) {
        ret += calc(ver[i]);
    }

    return ret;
}

int main() {
    int n, k;
    read(n, k);

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        read(u, v, w);

        add(u, v);
        add(v, u);
    }

    int t;
    for (int i = 0; i < k; ++i) {
        read(t);
        mark[t] = true;
    }

    dfs(t, 0);

    int ans = calc(t);

    
    write(ans);
    nl();
}