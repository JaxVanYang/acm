#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int sum = 0;
    int cnt = 0;
    for (int p = 0; p < n && cnt < k; ++p) {
        sum += s[p] - 'a' + 1;
        char ch = s[p];
        ++cnt;
        while (p + 1 < n && s[p + 1] - ch <= 1) ++p;
        // cout << "p = " << p << " cnt = " << cnt << endl;
    }
    if (cnt < k) puts("-1");
    else cout << sum << endl;
}