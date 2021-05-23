#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n, div = -1;
    cin >> n;
    bool flag = false;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            div = i;
            while (n % i == 0) {
                n /= i;
            }
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << n << endl;
        return 0;
    }
    if (n != 1) {
        cout << 1 << endl;
    } else {
        cout << div << endl;
    }
}