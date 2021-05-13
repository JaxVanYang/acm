#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
int a[maxn], sum[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    unordered_map<int, int> mp[2];
    mp[1][0] = 1;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = a[i] ^ sum[i];
        // cout << sum[i + 1] << ' ';
        mp[i & 1][sum[i + 1]]++;
    }
    // cout << endl;
    ll ans = 0;
    for (auto mp_ : mp) {
        for (auto [_, cnt] : mp_) {
            ans += (ll)cnt * (cnt - 1) / 2;
        }
    }
    printf("%lld\n", ans);
}