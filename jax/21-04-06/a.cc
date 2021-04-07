#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 105;
int n, b;
int a[maxn];
bool flags[maxn];
int costs[maxn];

int ans;

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int lCnt = 0;
    for (int i = 0; i < n; ++i) {
        if (2 * lCnt == i) flags[i] = 1;
        lCnt += a[i] & 1 ? 1 : 0;
    }
    int sz = 0;
    for (int p = 2; p < n; p += 2) {
        if (flags[p]) {
            costs[sz++] = abs(a[p] - a[p - 1]);
        }
    }
    sort(costs, costs + sz);
    int sum = 0;
    for (; ans < sz; ++ans) {
        if (sum + costs[ans] > b) break;
        sum += costs[ans];
    }
    cout << ans << endl;
}