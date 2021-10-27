#include <iostream>
#include <bitset>
using namespace std;

const int N = 3e6 + 100;
int trie[N][2], tot = 1;
bool ed[N];
int ans = INT32_MAX;

void insert(const bitset<30> &bits) {
    int len = bits.size(), p = 1;
    for (int i = len - 1; i >= 0; --i) {
        int ch = bits[i];
        if (trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    ed[p] = true;
}

void dfs(int u, int val) {
    if (ed[u]) {
        ans = min(ans, val);
        return;
    }

    if (trie[u][0] && trie[u][1]) {
        dfs(trie[u][0], val << 1 | 1);
        dfs(trie[u][1], val << 1 | 1);
    } else if (trie[u][0]) {
        dfs(trie[u][0], val << 1);
    } else if (trie[u][1]) {
        dfs(trie[u][1], val << 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        bitset<30> bits = bitset<30>(num);

        insert(bits);
    }

    dfs(1, 0);
    printf("%d\n", ans);
}