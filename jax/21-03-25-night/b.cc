#include <iostream>
using namespace std;
bool st[1005];

int main() {
    int n;
    cin >> n;
    int a[55], b[55];
    // cout << "yes" << endl;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int r = n - 1, l = n - 1;
    for (; l >= 0; --l) {
        if (!st[a[l]]) {
            st[a[l]] = 1;
            a[r] = a[l];
            r--;
        }
        // cout << "no" << endl;
    }
    cout << n - 1 - r << endl;
    for (int i = r + 1; i < n; ++i) cout << a[i] << ' ';
}