#include <iostream>
#include <cstring>
using namespace std;
using ull = unsigned long long;

const int N = 1e6 + 10;
char s[N];
const int P = 131;
ull p[N], f[N], g[N];
int idx = 0;

void init() {
    p[0] = 1;
    for (int i = 1; i < N; ++i) p[i] = p[i - 1] * P;
}


void solve() {
    int n = strlen(s + 1);

    f[0] = g[n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * P + s[i] - 'a';
    }
    for (int i = n; i >= 1; --i) {
        g[i] = g[i + 1] * P + s[i] - 'a';
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = min(i - 1, n - i);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            // printf("[%d, %d] [%d, %d]\n", i - mid, i, i + 1, i + 1 + mid);
            ull lft = f[i] - f[i - mid - 1] * p[mid + 1];
            ull rht = g[i] - g[i + mid + 1] * p[mid + 1];
            if (lft == rht) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        // printf("l = %d r = %d\n", l, r);
        ans = max(ans, l * 2 + 1);
        l = 0, r = min(i - 1, n - i - 1);
        if (l > r) continue;
        while (l < r) {
            
            int mid = l + r + 1 >> 1;
            ull lft = f[i] - f[i - mid - 1] * p[mid + 1];
            ull rht = g[i + 1] - g[i + mid + 2] * p[mid + 1];
            // printf("[%d, %d] [%d, %d]\n", i - mid, i, i + 1, i + 1 + mid  );
            if (lft == rht) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        // Note: there may be no even palindrome, so you should test it
        if (l != 0 || s[i] == s[i + 1])
            ans = max(ans, l * 2 + 2);
    }
    printf("Case %d: %d\n", idx, ans);
}

int main() {
    init();
    while (~scanf("%s", s + 1) && s[1] != 'E') {
        ++idx;
        solve();
    }
}