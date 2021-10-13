#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
// bool a[maxn];
int a[maxn];

int main() {
    int n;
    cin >> n;
    int lmt = n / 2;
    for (int i = 0; i < lmt; ++i) scanf("%d", a + i);
    sort(a, a + lmt);
    int ans = 0;
    for (int i = 0; i < lmt; ++i) {
        // cout << "i = " << i << " [] = " << a[i] << " tar = " << 2 * i + 1 << endl;
        ans += abs(a[i] - 2 * i - 1);
    }
    int tmp = 0;
    for (int i = 0; i < lmt; ++i) {
        // cout << "i = " << i << " [] = " << a[i] << " tar = " << 2 * i + 1 << endl;
        tmp += abs(a[i] - 2 * i - 2);
    }
    ans = min(ans, tmp);
    cout << ans << endl;
}