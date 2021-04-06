#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, w;
        scanf("%d%d", &n, &w);
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        map<int, int> mp;
        // use negetive element to transfer lower_bound(key) to return the last element less than or equal to key
        for (int i = 0; i < n; ++i) ++mp[-a[i]];
        int ans = 1, rest = -w;
        while (mp.size()) {
            auto p = mp.lower_bound(rest);

            if (p == mp.end()) {
                ++ans;
                rest = -w;
            } else {
                mp[p->first]--;
                rest -= p->first;
                if (mp[p->first] == 0) mp.erase(p->first);
            }
        }
        printf("%d\n", ans);
    }
}