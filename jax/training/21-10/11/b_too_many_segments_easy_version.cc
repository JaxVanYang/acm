#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 210;
int l[N], r[N];
bool vis[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", l + i, r + i);
    }

    vector<int> ans;

    for (int p = 1; p <= 200; ++p) {
        priority_queue<pair<int, int>> pq;

        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;

            if (l[i] <= p && p <= r[i]) {
                pq.push({r[i], i});
            }
        }

        while (pq.size() > k) {
            auto [rend, i] = pq.top();
            pq.pop();

            ans.push_back(i);
            vis[i] = true;
        }
    }

    printf("%ld\n", ans.size());
    for (int it : ans) {
        printf("%d ", it);
    }
    puts("");
}
