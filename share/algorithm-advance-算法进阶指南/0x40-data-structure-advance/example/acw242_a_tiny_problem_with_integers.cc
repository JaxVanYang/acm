#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
int a[N];
ll c[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) {
        c[x] += y;
    }
}

ll ask(int x) {
    ll ret = 0;
    for (; x; x -= lowbit(x)) {
        ret += c[x];
    }
    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    while (m--) {
        char ch;
        cin >> ch;

        if (ch == 'C') {
            int l, r, d;
            cin >> l >> r >> d;

            add(l, d);
            add(r + 1, -d);
        } else {
            int x;
            cin >> x;
            cout << a[x] + ask(x) << endl;
        }
    }
}