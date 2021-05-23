#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int a[100];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 2;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == 2 * d) ++ans;
        else if (a[i] - a[i - 1] > 2 * d) ans += 2;
    }
    cout << ans << endl;
}