#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
int c[N];
int ans[N];

int main() {
    int n, k;
    cin >> n >> k;

    ll sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];

        sum -= (ll)i * c[i];
    }

    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= k; ++i) {
        pq.push({c[i], i});
    }

    int p = k;

    for (int i = 1; i <= n; ++i) {
        if (++p <= n) {
            pq.push({c[p], p});
        }

        auto [cost, idx] = pq.top();

        // cout << "cost = " << cost << " idx = " << idx << endl;
        pq.pop();
        ans[idx] = k + i;

        sum += (ll)cost * ans[idx];
    }

    cout << sum << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}