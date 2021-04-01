#include <iostream>
#include <algorithm>
#include <queue>
// #include <deque>
#include <vector>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int p[maxn], c[maxn];
ll ans[maxn];

pair<int, int> mp[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", p + i);
    for (int i = 0; i < n; ++i) scanf("%d", c + i);
    for (int i = 0; i < n; ++i) mp[i] = make_pair(p[i], c[i]);
    sort(mp, mp + n);
    priority_queue<int> que;
    for (int i = 0; i < n; ++i) {
        vector<int> buf;
        ll sum = mp[i].second;
        for (int j = 0; j < k && que.size(); ++j) {
            sum += que.top();
            buf.push_back(que.top());
            que.pop();
        }
        for (auto &each : buf) que.push(each);
        que.push(mp[i].second);
        ans[i] = sum;
    }

    for (int i = 0; i < n; ++i) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mp[mid].first < p[i]) l = mid + 1; else r = mid;
        }
        printf("%lld ", ans[l]);
    }
}