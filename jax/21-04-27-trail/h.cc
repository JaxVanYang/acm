// 注意位运算的优先级

#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 1e7 + 10;
int cnts[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        ll num;
        scanf("%lld", &num);
        cnts[num % k]++;
    }
    // cout << cnts[1] << endl;
    ll ans = 0;
    for (int i = 1; 2 * i < k; ++i) {
        ans += (ll)cnts[i] * cnts[k - i];
    }
    if ((k & 1) == 0) {
        ans += (ll)cnts[k / 2] * (cnts[k / 2] - 1) / 2;
    }
    if (cnts[0] > 1) {
        ans += (ll)cnts[0] * (cnts[0] - 1) / 2;
    }
    printf("%lld\n", ans);
}