#include <iostream>
#include <map>
#include <cstring>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int cost[maxn];
int id[maxn];
int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

int main() {
    int n, k, m;
    // language words, groups, message words
    cin >> n >> k >> m;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        char s[21];
        scanf("%s", s);
        // cout << s << endl;
        mp[s] = i;
        id[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", cost + i);
        // cout << "cost " << i << " = " << cost[i] << endl;
    }
    for (int i = 0; i < k; ++i) {
        int x;
        int a;
        scanf("%d%d", &x, &a);
        if (x == 1) continue;
        int aId = find(a);
        for (int j = 1; j < x; ++j) {
            int b;
            scanf("%d", &b);
            int bId = find(b);
            if (aId != bId) {
                id[bId] = aId;
                cost[aId] = min(cost[aId], cost[bId]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        char s[25];
        scanf("%s", s);
        int id = find(mp[s]);
        // cout << "s = " << s << endl;
        // cout << "id = " << id << " cost = " << cost[id] << endl;
        ans += cost[id];
    }
    printf("%lld\n", ans);
}