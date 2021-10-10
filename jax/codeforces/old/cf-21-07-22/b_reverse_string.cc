#include <iostream>
#include <cstring>
using namespace std;

const int N = 505;

char s[N], t[N * 2];
int n, m;

bool dfs(int i, int j, bool isFirst) {
    if (j == m) return true;
    if (i < 0 || i >= n) return false;
    if (s[i] == t[j]) {
        if (isFirst) return dfs(i + 1, j + 1, true) || dfs(i - 1, j + 1, false);
        return dfs(i - 1, j + 1, false);
    }
    return false;
}

void solve() {
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; ++i) {
        if (dfs(i, 0, 1)) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
}