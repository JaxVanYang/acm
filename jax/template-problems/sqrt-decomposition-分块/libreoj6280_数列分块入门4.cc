#include <iostream>
#include <cctype>
#include <cmath>
using ll = long long;

template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) {
    read(t); read(args...);
}

const int N = 5e4 + 10, M = 300;
ll a[N], b[M], add[M];
int n, len;

inline int get_id(int x) {
    return x / len;
}

int query(int l, int r, ll p) {
    int ret = 0;
    int l_id = get_id(l), r_id = get_id(r);
    if (l_id == r_id) {
        for (int i = l; i <= r; ++i) ret = (ret + (a[i] % p)) % p;
        ret = (ret + (r - l + 1) * add[l_id] % p) % p;
    } else {
        if (l == l_id * len) {
            ret = (ret + b[l_id] % p) % p;
        } else {
            for (int i = l; i < (l_id + 1) * len; ++i) {
                ret = (ret + (a[i] % p)) % p;
                ret = (ret + add[l_id] % p) % p;
            }
        }
        if (r % len == len - 1) {
            ret = (ret + b[r_id] % p) % p;
        } else {
            for (int i = r_id * len; i <= r; ++i) {
                ret = (ret + a[i] % p) % p;
                ret = (ret + add[r_id] % p) % p;
            }
        }
        for (int i = l_id + 1; i < r_id; ++i) {
            ret = (ret + b[i] % p) % p;
        }
    }
    return ret;
}

void update(int l, int r, int c) {
    int l_id = get_id(l), r_id = get_id(r);

    if (l_id == r_id) {
        for (int i = l; i <= r; ++i) a[i] += c, b[l_id] += c;
    } else {
        if (l % len == 0) {
            add[l_id] += c;
            b[l_id] += (ll)c * len;
        } else {
            for (int i = l; i < (l_id + 1) * len; ++i) a[i] += c, b[l_id] += c;
        }

        if (r % len == len - 1) {
            add[r_id] += c;
            b[r_id] += (ll)c * len;
        } else {
            for (int i = r_id * len; i <= r; ++i) a[i] += c, b[r_id] += c;
        }
        for (int i = l_id + 1; i < r_id; ++i) b[i] += (ll)c * len, add[i] += c;
    }
}

int main() {
    read(n);
    for (int i = 0; i < n; ++i) read(a[i]);
    len = sqrt(n);

    for (int i = 0; i < n; ++i) b[get_id(i)] += a[i];

    while (n--) {
        int op, l, r;
        ll c;
        read(op, l, r, c);
        --l, --r;

        if (op) {
            int ans = query(l, r, c + 1);
            printf("%d\n", ans);
        } else {
            update(l, r, c);
        }
    }
}