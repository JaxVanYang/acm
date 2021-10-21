#include <cstdio>
#include <bits/stl_pair.h>
#include <bits/std_abs.h>
#include <cctype>
using namespace std;

template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t), read(args...);
}

const int N = 3e4 + 10;
int id[N], d[N], size[N];

int find(int p) {
    if (id[p] != p) {
        int root = find(id[p]);
        d[p] += d[id[p]];
        id[p] = root;
    }
    return id[p];
}

void un(int p, int q) {
    int pid = find(p), qid = find(q);
    if (pid == qid) return;
    id[pid] = qid, d[pid] = size[qid];
    size[qid] += size[pid];
}

int main() {
    for (int i = 1; i < N; ++i) {
        id[i] = i, d[i] = 0, size[i] = 1;
    }

    int t;
    read(t);

    while (t--) {
        char op;
        scanf("%c", &op);
        int x, y;
        read(x, y);

        if (op == 'M') {
            un(x, y);
        } else {
            int xid = find(x), yid = find(y);
            if (xid != yid) {
                puts("-1");
            } else {
                int ans = abs(d[x] - d[y]) - 1;
                if (ans < 0) ans = 0;
                printf("%d\n", ans);
            }
        }
    }
}