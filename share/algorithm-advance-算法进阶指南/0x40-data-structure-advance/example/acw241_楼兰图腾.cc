#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int l[2][N], r[2][N], a[N];
int arr[N];
int n;

inline int lowbit(int n) {
    return n & -n;
}

void add(int x) {
    while (x <= n) {
        ++arr[x];
        x += lowbit(x);
    }
}

int ask(int x) {
    int ans = 0;

    while (x) {
        ans += arr[x];
        x -= lowbit(x);
    }

    return ans;
}

inline int ask(int l, int r) {
    return ask(r) - ask(l - 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= n; ++i) {
        l[0][i] = ask(a[i]);
        l[1][i] = ask(a[i], n);

        add(a[i]);
    }

    fill(arr + 1, arr + n + 1, 0);

    for (int i = n; i >= 1; --i) {
        r[0][i] = ask(a[i]);
        r[1][i] = ask(a[i], n);

        add(a[i]);
    }

    ll ans[2] = {};

    for (int i = 1; i <= n; ++i) {
        ans[0] += (ll)l[1][i] * r[1][i];
        ans[1] += (ll)l[0][i] * r[0][i];
    }

    printf("%lld %lld\n", ans[0], ans[1]);
}