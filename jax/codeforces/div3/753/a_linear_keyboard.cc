#include <iostream>
#include <cstring>

const int N = 55;
int pos[256];
char s[N];
char t[N];

void solve() {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); ++i) {
        pos[s[i]] = i;
    }
    scanf("%s", t);
    int ans = 0;
    for (int i = 1; i < strlen(t); ++i) {
        ans += std::abs(pos[t[i]] - pos[t[i - 1]]);
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