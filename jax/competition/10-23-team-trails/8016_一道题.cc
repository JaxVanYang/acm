#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int n;
int a[N], lbs[N], rbs[N], lbit[N][30], rbit[N][30];

void init() {
    a[0] = a[n + 1] = INT32_MAX;
    stack<int> lstk, rstk;
    lstk.push(0), rstk.push(n + 1);
    for (int i = 0; i < 30; ++i) rbit[n + 1][i] = n + 1;
    for (int i = 1; i <= n; ++i) {
        while (a[lstk.top()] <= a[i]) lstk.pop();
        lbs[i] = lstk.top();
        lstk.push(i);

        for (int j = 0; j < 30; ++j) {
            if ((a[i] >> j) & 1) {
                lbit[i][j] = i;
            } else {
                lbit[i][j] = lbit[i - 1][j];
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        while (a[rstk.top()] <= a[i]) rstk.pop();
        rbs[i] = rstk.top();
        rstk.push(i);

        for (int j = 0; j < 30; ++j) {
            if ((a[i] >> j) & 1) {
                rbit[i][j] = i;
            } else {
                rbit[i][j] = rbit[i + 1][j];
            }
        }
    }
}

int get_ly(int idx) {
    int ret = 0;
    for (int i = 0; i < 30; ++i) {
        if ((a[idx] >> i) & 1) continue;
        ret = max(ret, lbit[idx][i]);
    }
    return ret;
}
int get_ry(int idx) {
    int ret = n + 1;
    for (int i = 0; i < 30; ++i) {
        if ((a[idx] >> i) & 1) continue;
        ret = min(ret, rbit[idx][i]);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    init();

    unordered_map<int, int> pre;
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        int lb = lbs[i], rb = rbs[i];
        if (pre.count(a[i])) lb = max(lb, pre[a[i]]);
        // cout << "lb = " << lb << " rb = " << rb << endl;
        pre[a[i]] = i;

        int ly = get_ly(i), ry = get_ry(i);
        // cout << "ly = " << ly << " ry = " << ry << endl;

        ans += (ll)(i - lb) * (rb - i);
        // cout << "plus = " << (ll)(i - lb) * (rb - i) << endl;
        ans -= (ll)(i - max(lb, ly)) * (min(rb, ry) - i);
        // cout << "minus = " << (ll)(i - max(lb, ly)) * (min(rb, ry) - i) << endl;
    }

    printf("%lld\n", ans);
}