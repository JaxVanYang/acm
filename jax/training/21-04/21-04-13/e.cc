#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int sum = x + y;
        int cnt0 = (n + 1) / 2;
        int cnt1 = n - cnt0;
        ll pre = 0ll;
        pre += (x - 1) / 2 * (ll)n;
        if (sum & 1) {
            if (n & 1) pre += 1;
            pre += (ll)n * n / 2;
            // cout << "pre = " << pre << endl;
            if (x & 1) {
                pre += y / 2;
            } else {
                pre += cnt1;
                pre += y / 2 + 1;
            }
        } else {
            // cout << "pre = " << pre << endl;
            if (x & 1) {
                pre += y / 2 + 1;
            } else {
                pre += cnt0;
                // cout << "pre = " << pre << endl;
                pre += y / 2;
            }
        }
        cout << pre << endl;
    }
}