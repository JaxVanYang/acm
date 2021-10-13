#include <iostream>
using namespace std;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int ans = n - (a + b - c);
    if (ans >= 1 && c <= min(a, b) && a + b - c <= n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}