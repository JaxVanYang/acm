#include <iostream>

const int N = 1e5 + 10;
int head[N * 2], next[N * 2], ver[N * 2], edge[N * 2], tot = 1;
int d[N];
bool mark[N];   // 标记已遍历的点

int trie[31 * N][2], trie_tot = 1;

inline void add(int u, int v, int w) {
    ver[++tot] = v, edge[tot] = w;
    next[tot] = head[u], head[u] = tot;
}

void insert(int num) {
    int p = 1;
    for (int i = 30; i >= 0; --i) {
        int val = (num >> i) & 1;
        if (trie[p][val] == 0) {
            trie[p][val] = ++trie_tot;
        }
        p = trie[p][val];
    }
}

void dfs(int u) {
    for (int i = head[u]; i; i = next[i]) {
        int v = ver[i], w = edge[i];
        if (mark[v]) continue;
        mark[v] = 1;
        d[v] = d[u] ^ w;
        dfs(v);
    }
}

int query(int num) {
    int ret = 0, p = 1;
    for (int i = 30; i >= 0; --i) {
        int val = !((num >> i) & 1);
        if (trie[p][val] == 0) {
            val ^= 1;
        }
        // printf("val = %d\n", val);
        p = trie[p][val];
        ret = (ret << 1) + val;
    }
    return num ^ ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        // Trick: 加入双边，将树扩展为图，即可通过任意一点遍历所有结点
        add(u, v, w);
        add(v, u, w);
    }

    mark[0] = 1;
    // 因为最终只要用到任意两点的路径异或，所以从任意一点 dfs 都可
    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        insert(d[i]);
        ans = std::max(ans, query(d[i]));
    }
    printf("%d\n", ans);
}