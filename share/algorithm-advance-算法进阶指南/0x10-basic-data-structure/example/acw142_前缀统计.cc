#include <iostream>
#include <cstring>

const int N = 1e6 + 20;
int trie[N][26], tot = 1;
int end[N * 26];
char s[N];

void insert(char *s) {
    int p = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int id = s[i] - 'a';
        if (trie[p][id] == 0) {
            trie[p][id] = ++tot;
        }
        p = trie[p][id];
    }
    end[p]++;
}

int query(char *s) {
    int ret = 0;
    int p = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int id = s[i] - 'a';
        if (trie[p][id] == 0) return ret;
        p = trie[p][id];
        ret += end[p];
    }
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        insert(s);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
}