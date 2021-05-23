#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];

inline void remove(string &s, char ch) {
    size_t pos = s.find(ch);
    if (pos >= s.length()) return;
    s.erase(pos, 1);
}

bool check() {
    int l = 0, n = strlen(s);
    while (l < n) {
        while (l < n && s[l] == '?') {
            ++l;
        }
        if (l < n - 1 && s[l + 1] == s[l]) {
            return false;
        }
        ++l;
    }
    return true;
}

void solve() {
    scanf("%s", s);
    if (!check()) {
        puts("-1");
        return;
    }
    int l = 0;
    int n = strlen(s);
    while (l < n) {
        while (l < n && s[l] != '?') {
            ++l;
        }
        int r = l;
        while (r < n && s[r] == '?') {
            ++r;
        }
        string chs = "abc";
        if (l == 0 && r != n) {
            remove(chs, s[r]);
        } else if (l != 0 && r == n) {
            remove(chs, s[l - 1]);
        } else if (l != 0 && r != n) {
            if (r - l == 1 && s[l] != s[r]) {
                remove(chs, s[l - 1]);
                remove(chs, s[r]);
                s[l++] = chs.front();
            } else if (s[l - 1] != s[r]) {
                s[l++] = s[r];
            }
            remove(chs, s[r]);
        }
        for (int i = l; i < r; ++i) {
            s[i] = chs[i & 1];
        }
        l = r + 1;
    }
    printf("%s\n", s);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }
}