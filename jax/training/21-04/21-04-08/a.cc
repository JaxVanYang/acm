#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

// int a[maxn];
char s[maxn];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    string ans;
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') ++cnt;
        else ans += s[i];
    }
    int p = 0;
    while (p < ans.length() && ans[p] != '2') ++p;
    // cout << "ans = " << ans << " p = " << p << endl;
    cout << ans.substr(0, p);
    for (int i = 0; i < cnt; ++i) putchar('1');
    cout << ans.substr(p);
    // printf("%s", s);
}