#include <iostream>
using namespace std;
const int maxn = 1005;
int a[maxn], c[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%d", c + i);
    for (int i = 0; i < m; ++i) scanf("%d", a + i);
    int ans = 0, l = 0, r = 0;
    while (l < n && r < m) {
        if (c[l] <= a[r]) {
            ++l;
            ++r;
            ++ans;
        } else {
            ++l;
        }
    }
    cout << ans << endl;
}