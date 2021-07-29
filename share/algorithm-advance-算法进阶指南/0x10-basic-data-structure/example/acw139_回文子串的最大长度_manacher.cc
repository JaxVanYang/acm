// Manacher 算法，参考：https://cp-algorithms.com/string/manacher.html

#include <iostream>
#include <cstring>
using namespace std;
using ull = unsigned long long;

const int N = 1e6 + 10;
char s[N];
int d1[N], d2[N];
int idx = 0;

void solve() {
    int n = strlen(s);

    int ans = 1;
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            ++k;
        }
        ans = max(ans, k * 2 - 1);
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            ++k;
        }
        ans = max(ans, k * 2);
        d2[i] = k--;
        if (i + k > r) {
            l = i - 1 - k;
            r = i + k;
        }
    }
    printf("Case %d: %d\n", idx, ans);
}

int main() {
    while (~scanf("%s", s) && s[0] != 'E') {
        ++idx;
        solve();
    }
}