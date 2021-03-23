#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll transfer(ll num) {
    ll ret = 0;
    vector<int> vals;
    while (num > 0) {
        vals.push_back(num % 10);
        num /= 10;
    }
    for (int i = 0; i < 2 * vals.size(); ++i) {
        ret = ret * 10 + vals[vals.size() - 1 - i % vals.size()];
    }
    return ret;
}
int main() {
    ll n;
    // cout << transfer(90) << endl;
    cin >> n;
    ll l = 0, r = 1e9;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (transfer(mid) > n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l - 1 << endl;
}