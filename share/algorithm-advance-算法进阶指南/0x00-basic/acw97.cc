#include <iostream>
using namespace std;
const int mod = 9901;

int quick(int a, int b) {
    int res = 1;
    a = a % mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int sum(int p, int k) {
    if (k == 0) return 1;
    if (k % 2 == 0) {
        return (p % mod * sum(p, k - 1) + 1) % mod;
    }
    return (1 + quick(p, k / 2 + 1)) * sum(p, k / 2) % mod;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 1;
    for (int i = 2; i <= a; ++i) {
        int s = 0;
        while (a % i == 0) {
            ++s;
            a /= i;
        }
        if (s) ans = ans * sum(i, s * b) % mod;
    }
    if (!a) ans = 0;
    cout << ans << endl;
}