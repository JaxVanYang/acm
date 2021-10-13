#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    ll lmt = min(n, k);
    ll low = k / 2;
    // if (k & 1) {
    //     ++low;
    // }
    // cout << "low = " << low << " lmt = " << lmt << endl;
    ll ans = min(k - 1, lmt) - low;
    ans = max(0ll, ans);
    cout << ans << endl;
}