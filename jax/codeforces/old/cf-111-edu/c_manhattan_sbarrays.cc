#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int check(int l, int r) {
    // cout << "l = " << l << " r = " << r << endl;
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r; ++j) {
            for (int k = j + 1; k < r; ++k) {
                // cout << a[i] << " " << a[j] << " " << a[k] << endl;
                if (min(a[i], a[k]) <= a[j] && a[j] <= max(a[i], a[k])) return 0;
            }
        }
    }
    // cout << "yes l = " << l << " r = " << r << endl;
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d",a + i);
        int ans = n + n - 1;
        for (int l = 0; l < n - 2; ++l) {
            for (int r = l + 3; r <= min(n, l + 4); ++r) {
                ans += check(l, r);
            }
        }
        printf("%d\n", ans);
    }
}