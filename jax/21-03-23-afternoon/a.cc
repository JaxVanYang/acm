#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    int k = -1;
    ll tmp = 1;
    while (n - tmp >= 0) {
        ++k;
        if (tmp > 2e17) break;
        tmp *= 5;
    }
    cout << k << " " << tmp << endl;
}