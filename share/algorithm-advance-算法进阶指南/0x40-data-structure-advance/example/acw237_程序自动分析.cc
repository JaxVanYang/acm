#include <bits/stdc++.h>
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

const int N = 1e5 + 10, M = 2 * N;
int a[M], len1 = 0, len2 = 0, n, m, id[M], w[M];
pair<int, int> equals[N], no_equal[N];

inline void reset() {
    len1 = len2 = 0;
}

inline int query(int val) {
    return lower_bound(a, a + m, val) - a;
}

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

void un(int p, int q) {
    int pid = find(p), qid = find(q);
    if (pid == qid) return;
    int pw = w[pid], qw = w[qid];
    if (pw < qw) {
        id[pid] = qid;
        w[qid] += pw;
    } else {
        id[qid] = pid;
        w[pid] += qw;
    }
    // id[find(p)] = find(q);
}

void solve() {
    read(n);
    reset();

    for (int i = 0; i < n; ++i) {
        int x, y, e;
        read(x, y, e);
        a[i << 1] = x, a[i << 1 | 1] = y;

        if (e == 1) {
            equals[len1++] = {x, y};
        } else {
            no_equal[len2++] = {x, y};
        }
    }

    m = 2 * n;
    sort(a, a + m);
    m = unique(a, a + m) - a;
    // cout << "m = " << m << endl;

    for (int i = 0; i < m; ++i) {
        id[i] = i;
        w[i] = 1;
    }

    for (int i = 0; i < len1; ++i) {
        auto [x, y] = equals[i];
        int p = query(x), q = query(y);
        un(p, q);
        // cout << "p = " << p << " q = " << q << " pid = " << id[p] << " qid = " << id[q] << endl;
    }

    // for (int i = 0; i < m; ++i) {
        // cout << a[i] << ' ';
    // }
    // cout << endl;

    // for (int i = 0; i < m; ++i) {
        // cout << find(i) << ' ';
    // }
    // cout << endl;

    for (int i = 0; i < len2; ++i) {
        auto [x, y] = no_equal[i];
        int p = query(x), q = query(y);
        // cout << "p = " << p << " q = " << q << endl;

        if (find(p) == find(q)) {
            puts("NO");
            return;
        }
    }

    puts("YES");
}

int main() {
    int t;
    read(t);

    while (t--) {
        solve();
    }
}