#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn], t[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    int len = min(n, m);
    int l = 0;
    while (l < len && s[l] == t[l]) {
        ++l;
    }
    int l1 = l;
    // cout << "l = " << l  << " n = " << n << endl;
    if (l < n && s[l] == '*') {
        ++l;
        if (l == n) {
            puts("YES");
            return 0;
        }
    }
    int r0 = max(l, n - 1), r1 = max(l1, m - 1);
    // cout << "l = " << l << " l1 = " << l1 << " r0 = " << r0 << " r1 = " << r1 << endl;
    while (l <= r0 && l1 <= r1) {
        if (s[r0--] != t[r1--]) {
            puts("NO");
            return 0;
        }
    }
    if (r0 != l - 1) {
        puts("NO");
    } else {
        puts("YES");
    }
}