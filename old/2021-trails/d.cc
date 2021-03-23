#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int cnts[maxn];
// int maxF = 1;

void divide(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) x /= i, ++cnt;
            cnts[i] = (cnts[i] + cnt) % mod;
        }
    }
    if (x > 1) cnts[x] = (cnts[x] + 1) % mod;
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        divide(i);
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = (ll)ans * (cnts[i] + 1) % mod;
    }
    cout << ans << endl;
}