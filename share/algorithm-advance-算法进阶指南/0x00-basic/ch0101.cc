#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    ll ans = 1 % p; // p 为 1 的时候答案必为 0
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        b >>= 1;    // 记得加等号
        a = a * a % p;
    }
    cout << ans << endl;
}