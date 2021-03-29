#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int c[maxn];

int main() {
    int n;
    cin >> n;
    c[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int p = i - 1;
        for (int j = 0; 2 * j < p; ++j) c[i] = (c[i] + (ll)c[j] * c[i - 1 - j] % mod) % mod;
        c[i] = 2 * c[i] % mod;
        if (p % 2 == 0) {
            c[i] = (c[i] + (ll)c[p / 2] * c[p / 2] % mod) % mod;
        }
        
    }
    printf("%d", c[n]);
}