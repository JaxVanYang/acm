#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[105];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (a[l] <= k) {
            ans++;
            l++;
        } else if (a[r] <= k) {
            ans++;
            r--;
        } else {
            break;
        }
    }
    cout << ans << endl;
}