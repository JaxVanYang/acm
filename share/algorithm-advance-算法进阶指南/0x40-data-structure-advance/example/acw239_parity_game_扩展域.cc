#include <cstdio>
#include <iostream>
#include <algorithm>

const int M = 1e4 + 10, N = M << 2;
int a[N], len = 0, id[N];

struct Node {
    int l, r, flag;
} nodes[M];

inline int query(int val) {
    return std::lower_bound(a, a + len, val) - a;
}

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

inline void un(int p, int q) {
    id[find(p)] = find(q);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char s[10];

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%s", &nodes[i].l, &nodes[i].r, s);
        a[len++] = --nodes[i].l;
        a[len++] = nodes[i].r;
        if (s[0] == 'e') {
            nodes[i].flag = 0;
        } else {
            nodes[i].flag = 1;
        }
    }

    std::sort(a, a + len);
    len = std::unique(a, a + len) - a;
    for (int i = 0; i < 2 * len; ++i) {
        id[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        auto [l, r, flag] = nodes[i];
        int p = query(l), q = query(r);
        int p_ = p + len, q_ = q + len;

        if (flag == 0) {
            if (find(p) == find(q_)) {
                printf("%d\n", i);
                return 0;
            }
            un(p, q), un(p_, q_);
        } else {
            if (find(p) == find(q)) {
                printf("%d\n", i);
                return 0;
            }
            un(p, q_), un(p_, q);
        }
    }
    printf("%d\n", m);
}