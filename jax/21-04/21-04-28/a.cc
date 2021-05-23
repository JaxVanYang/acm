#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll cnt = 0;
    ll a = 2 * n, b = 5 * n, c = 8 * n;
    cnt += (a + k - 1) / k;
    cnt += (b + k - 1) / k;
    cnt += (c + k - 1) / k;
    cout << cnt << endl;
}