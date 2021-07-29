#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
char s[N];
size_t n, case_no = 0;
const char el = '\n';

void solve() {
    cout << "Test case #" << case_no << el;
    cin >> s;

    vector<size_t> f(n);
    for (size_t i = 1; i < n; ++i) {
        size_t len = f[i - 1];
        while (len > 0 && s[len] != s[i]) {
            len = f[len - 1];
        }
        if (s[len] == s[i]) {
            ++len;
        }
        f[i] = len;

        size_t cur_len = i + 1;
        size_t rep_len = cur_len - len;
        size_t rep_time = cur_len / rep_len;
        // cout << "rep_len = " << rep_len << el;
        if (cur_len % rep_len == 0 && rep_time > 1) {
            cout << cur_len << ' ' << rep_time << el;
        }
    }

    cout << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n && n) {
        ++case_no;
        solve();
    }
}