#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = min(a, b);
        a -= ans;
        b -= ans;
        ans *= 2;
        ans += a / 3 * 3 + (a % 3 == 2 ? 1 : 0);
        ans += b / 3 * 6 + (b % 3 == 2 ? 4 : 0);
        cout << ans << endl;
    }
}