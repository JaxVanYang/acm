#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
pair<int, int> arr[maxn];

int main() {
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr + n);
    ll ans = 0, cur = 0;
    int l = 0, r = 0;

    while (l < n) {
        while (r < n && arr[r].first < arr[l].first + d) {
            cur += arr[r++].second;
        }
        ans = max(ans, cur);
        cur -= arr[l++].second;
    }
    printf("%lld\n", ans);
}