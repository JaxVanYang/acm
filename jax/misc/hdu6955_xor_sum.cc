#include <iostream>
#include <cstring>

const int N = 1e5 + 10;
int sum[N];
int trie[N * 30][2], end[N * 60], tot = 1;

void insert(int num, int id) {
    int p = 1;
    for (int i = 29; i >= 0; --i) {
        int val = (num >> i) & 1;
        if (trie[p][val] == 0) {
            trie[p][val] = ++tot;

            // 因为字典树可能只被部分重置，所以需要在扩展新结点的时候动态重置
            trie[tot][0] = trie[tot][1] = 0;
            end[tot] = 0;
        }
        p = trie[p][val];
    }
    end[p] = id;
}

void reset() {
    // Note: memset TLE
    // memset(trie, 0, sizeof trie);
    // memset(end, 0, sizeof end);
    trie[1][0] = trie[1][1] = 0;
    end[1] = 0;
    tot = 1;
}

int n, k, l, r;

void dfs(int p, int bit, int num, int id, bool pre) {
    // printf("p = %d bit = %d\n", p, bit);
    if (bit == -1) {
        // printf("p = %d l = %d r = %d end = %d id = %d\n", p, l, r, end[p] + 1, id);
        if (l == -1 || r - l > id - end[p] - 1) {
            l = end[p] + 1;
            r = id;
        }
        return;
    }
    int k_val = (k >> bit) & 1;
    int num_val = (num >> bit) & 1;
    if (pre) {
        // Note: 并不是只能选其一
        if (trie[p][0]) dfs(trie[p][0], bit - 1, num, id, true);
        if (trie[p][1]) dfs(trie[p][1], bit - 1, num, id, true);
    } if (k_val) {
        int val = k_val ^ num_val;
        if (trie[p][val]) dfs(trie[p][val], bit - 1, num, id, false);
    } else {
        if (num_val) {
            if (trie[p][0]) dfs(trie[p][0], bit - 1, num, id, true);
            if (trie[p][1]) dfs(trie[p][1], bit - 1, num, id, false);
        } else {
            if (trie[p][0]) dfs(trie[p][0], bit - 1, num, id, false);
            if (trie[p][1]) dfs(trie[p][1], bit - 1, num, id, true);
        }
    }
}

void solve() {
    l = r = -1;
    reset();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", sum + i);
        sum[i] ^= sum[i - 1];
    }

    for (int i = 0; i <= n; ++i) {
        dfs(1, 29, sum[i], i, false);
        if (l != -1 && r == l) break;
        insert(sum[i], i);
    }
    if (l == -1) {
        puts("-1");
    } else {
        printf("%d %d\n", l, r);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}