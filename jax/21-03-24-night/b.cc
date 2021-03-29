#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    int r, c;
    if (k < n) {
        r = k + 1, c = 1;
    } else {
        k -= n;
        int cnt = k / (m - 1);
        r = n - cnt;
        if (cnt & 1) {
            c = m - k % (m - 1);
        } else {
            c = 2 + k % (m - 1);
        }
    }
    printf("%d %d", r, c);
}