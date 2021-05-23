#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 2e5 + 100;

int a[maxn];
char s[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    memset(s, '0', sizeof(s));
    s[n] = '\0';
    int l = 0, r = n - 1;
    int val = n - 1;
    while (l <= r) {
        if (r - l == val) {
            s[val] = '1';
        }
        if (a[l] > a[r]) {
            val = min(val, a[l++] - 2);
        } else {
            val = min(val, a[r--] - 2);
        }
    }
    printf("%s\n", s);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}