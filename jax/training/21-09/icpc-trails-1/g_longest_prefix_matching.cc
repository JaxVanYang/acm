#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 32 * N;
char hop[N][16];

int trie[M][2], ed[M], tot = 1;

void trans(char *s) {
    int len = strlen(s), p = 0;
    int vals[4] = {0};

    for (int i = 0; i < 4 && p < len; ++i) {
        // printf("vals[%d] = %d\n", i, vals[i]);
        while (p < len && s[p] != '.') {
            vals[i] = vals[i] * 10 + s[p++] - '0';
        }
        ++p;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            s[i * 8 + j] = '0' + ((vals[i] >> (7 - j)) & 1);
        }
    }

    s[32] = '\0';
}

void insert(char *s, int len, int id) {
    int p = 1;

    for (int i = 0; i < len; ++i) {
        int val = s[i] - '0';
        if (!trie[p][val]) {
            trie[p][val] = ++tot;
        }
        p = trie[p][val];
    }

    ed[p] = id;
}

int search(char *s) {
    int len = strlen(s), p = 1, ret;

    for (int i = 0; i < len; ++i) {
        int val = s[i] - '0';

        if (ed[p]) {
            ret = ed[p];
        }

        p = trie[p][val];
        if (!p) {
            return ret;
        }

        // cout << "ret = " << hop[ret] << endl;
    }

    if (ed[p]) {
        ret = ed[p];
    }

    // cout << "ret = " << hop[ret] << endl;

    return ret;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        char ip[40];
        int mask;

        scanf("%s%d%s", ip, &mask, hop[i]);
        // printf("before: %s\n", ip);

        trans(ip);
        // printf("after: %s\n", ip);

        insert(ip, mask, i);
    }

    int q;
    scanf("%d", &q);

    for (int i = 1; i <= q; ++i) {
        char ip[40];
        scanf("%s", ip);

        // printf("before: %s\n", ip);

        trans(ip);
        // printf("after: %s\n", ip);

        int id = search(ip);

        printf("%s\n", hop[id]);
    }
}