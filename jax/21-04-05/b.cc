#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int tar = ceil(4.5 * n);
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    sort(a, a + n);
    int i = 0;
    int ans = 0;
    // cout << "sum = " << sum << " tar = " << tar << endl;
    while (sum < tar) {
        sum += 5 - a[i++];
        ++ans;
    }
    cout << ans << endl;
}