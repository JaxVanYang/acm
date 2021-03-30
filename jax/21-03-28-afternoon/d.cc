#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll l, r;
    cin >> l >> r;
    ll len = r - l + 1;
    ll left = ((len + 1) >> 1) % 4;
    if (len & 1) {
        if (left == 1) cout << len;
        else if (left == 2) cout << 2;
        else if (left == 3) cout << len + 2;
        else cout << 0;
    } else {
        if (left == 1) cout << 2;
        else if (left == 2) cout << len + 2;
        else if (left == 3) cout << 0;
        else cout << len;
    }
}