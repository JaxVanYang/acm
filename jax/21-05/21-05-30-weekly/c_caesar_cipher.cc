#include <iostream>
using namespace std;

const int maxn = 55;
char s[3][maxn];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 3; ++i) scanf("%s", s + i);
    int shift = (s[0][0] - s[1][0] + 26) % 26;
    for (int i = 0; i < m; ++i) s[2][i] = 'A' + (s[2][i] - 'A' + shift) % 26;
    puts(s[2]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
}