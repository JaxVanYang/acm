#include <iostream>
#include <cstring>

void solve() {
    int n;
    scanf("%d", &n);
    std::string s = std::to_string(n);

    if (*s.rbegin() % 2 == 0) {
        puts("0");
    } else if (*s.begin() % 2 == 0) {
        puts("1");
    } else {
        for (int i = 1; i < s.size() - 1; ++i) {
            if (s[i] % 2 == 0) {
                puts("2");
                return;
            }
        }
        puts("-1");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}