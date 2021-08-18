#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans, max_cnt = -1;
int primes[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int c[11];
int n;

int count() {
    int ret = 1;
    for (int i = 1; i <= 10; ++i) {
        ret *= (c[i] + 1);
    }
    return ret;
}

void dfs(ll cur, int p) {
    if (cur > n) return;
    // if (count() > 30) return;
    auto sum = accumulate(c + 1, c + p, 0);
    // cout << "sum = " << sum << endl;
    if (sum > 30) return;
    // if (sum > 30) return;
    // cout << "cur = " << cur << endl;
    if (p == 11) {
        int cnt = count();
        if (cnt > max_cnt) {
            max_cnt = cnt;
            ans = cur;
        } else if (cnt == max_cnt && cur < ans) {
            ans = cur;
        }
        return;
    }

    ll base = 1;
    for (int i = 0; i <= 30; ++i) {
        ll nex = cur * base;
        c[p] = i;
        if (nex > n) return;
        dfs(nex, p + 1);
        base *= primes[p];
    }
}

int main() {
    c[0] = INT32_MAX;
    cin >> n;
    dfs(1, 1);
    cout << ans << endl;
}