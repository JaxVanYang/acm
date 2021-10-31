#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
int a[N];
ll sum[N], c[2][N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int id, int x, int y) {
    for (; x <= n; x += lowbit(x)) c[id][x] += y;
}

ll ask(int id, int x) {
    ll ret = 0;
    for (; x; x -= lowbit(x)) ret += c[id][x];
    return ret;
}

inline ll calc(int x) {
    return sum[x] + (ll)(x + 1) * ask(0, x) - ask(1, x);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }

    while (m--) {
        char op[1];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        // cout << "op = " << op << endl;

        if (op[0] == 'C') {
            scanf("%d", &d);
            add(0, l, d);
            add(0, r + 1, -d);
            add(1, l, l * d);
            add(1, r + 1, (ll)(-r - 1) * d);
        } else {
            printf("%lld\n", calc(r) - calc(l - 1));
        }
    }
}