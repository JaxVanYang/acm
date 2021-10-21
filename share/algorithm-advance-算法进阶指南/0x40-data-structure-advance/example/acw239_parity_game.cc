#include <cstdio>
#include <algorithm>
using namespace std;

const int M = 1e4, N = 2 * M;
int a[N], len;
char s[10];
int op[M][3], id[N], d[N];

inline int query(int val) {
    return lower_bound(a, a + len, val) - a;
}

int find(int p) {
    if (id[p] != p) {
        int pid = find(id[p]);
        d[p] ^= d[id[p]];
        id[p] = pid;
    }
    return id[p];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    len = 2 * m;

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%s", op[i], op[i] + 1, s);
        a[i << 1] = --op[i][0], a[i << 1 | 1] = op[i][1];

        if (s[0] == 'e') {
            op[i][2] = 0;
        } else {
            op[i][2] = 1;
        }
    }

    sort(a, a + len);
    len = unique(a, a + len) - a;

    for (int i = 0; i < len; ++i) {
        id[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int l = op[i][0], r = op[i][1], val = op[i][2];

        int p = query(l), q = query(r);
        int pid = find(p), qid = find(q);
        if (pid == qid) {
            if (d[p] ^ d[q] != val) {
                printf("%d\n", i);
                return 0;
            }
        } else {
            id[pid] = qid;
            d[pid] = d[p] ^ d[q] ^ val;
        }
    }

    printf("%d\n", m);
}