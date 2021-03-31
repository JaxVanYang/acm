#include <iostream>
// #include <stack>
#include <vector>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
ll lft[maxn], rht[maxn];

inline int count(const string &s) {
    int cnt0 = 0, cnt1 = 0;
    for (auto &ch : s) if (ch == '(') cnt0++; else cnt1++;
    return abs(cnt0 - cnt1);
}

inline bool isLeft(const string &s) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') cnt0++; else cnt1++;
        if (cnt1 > cnt0) return false;
    }
    return true;
}

inline bool isRight(const string &s) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '(') cnt0++; else cnt1++;
        if (cnt1 < cnt0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        // scanf("%s", s);
        cin >> s;
        // cout << s << " : " << cnt << endl;
        if (isLeft(s)) {
            int cnt = count(s);
            // cout << "left " << cnt << endl;
            lft[cnt]++;
            if (cnt == 0) rht[0]++;
        } else if (isRight(s)) {
            int cnt = count(s);
            rht[cnt]++;
            // cout << "right " << cnt << endl;
        }
    }

    ll ans = 0;
    for (int i = 0; i < maxn; ++i) ans += lft[i] * rht[i];
    printf("%lld", ans);
}