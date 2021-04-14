#include <iostream>
#include <vector>
using namespace std;

vector<char> st[26];

void getSt() {
    st[0] = {'b'};
    st[25] = {'y'};
    for (int i = 1; i < 25; ++i) {
        st[i] = {char('a' + i - 1), char('a' + i + 1)};
    }
}

bool hasSame(char a, char b) {
    for (char ch0 : st[a - 'a']) {
        for (char ch1 : st[b - 'a']) {
            if (ch0 == ch1) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; ++i) {
        if (!hasSame(s[i], s[n - 1 - i])) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t;
    cin >> t;
    getSt();
    while (t--) {
        solve();
    }
}