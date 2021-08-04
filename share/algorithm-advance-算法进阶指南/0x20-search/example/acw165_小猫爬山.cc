#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, w;
int ans = INT32_MAX;
int a[N], cab[N];

void dfs(int cur, int cnt) {
    if (cnt >= ans) return;
    if (cur == n) ans = min(ans, cnt);
    for (int i = 1; i <= cnt; ++i) {
        if (cab[i] + a[cur] <= w) {
            cab[i] += a[cur];
            dfs(cur + 1, cnt);
            cab[i] -= a[cur];
        }
    }
    cab[cnt + 1] = a[cur];
    dfs(cur + 1, cnt + 1);
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, greater<int>());
    dfs(0, 0);
    cout << ans << endl;
}