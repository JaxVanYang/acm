#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll x;
        cin >> n >> m >> x;
        x--;
        // cout << "x = " << x << endl;
        int c = x / n, r = x % n;
        ll ans = (ll)r * m + c;
        cout << ans + 1 << endl;
    }
}

