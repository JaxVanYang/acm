#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    // if (n % 2) cout << a[(n - 1) / 2] << endl;
    // else cout << a[n / 2] << endl;
    int mid = a[n / 2];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(mid - a[i]);
    }
    cout << ans << endl;
}