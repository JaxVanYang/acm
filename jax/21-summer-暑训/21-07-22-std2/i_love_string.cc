#include <iostream>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
char s[N];
int n;

void solve() {
    scanf("%d%s", &n, s);

    int ans = 1;
    for (int i = 1; i < n && s[i] == s[0]; ++i) {
        ans = ans * 2 % mod;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}