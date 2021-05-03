#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
// 记录每种可作为左边或右边的括号序列个数
ll lft[maxn], rht[maxn];

// 计算左括号与右括号个数的差值
inline int count(const string &s) {
    int cnt0 = 0, cnt1 = 0;
    for (auto &ch : s) if (ch == '(') cnt0++; else cnt1++;
    return abs(cnt0 - cnt1);
}

// 判断是否可作为左边的括号序列
inline bool isLeft(const string &s) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') cnt0++; else cnt1++;
        if (cnt1 > cnt0) return false;
    }
    return true;
}

// 判断是否可作为右边的括号序列
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
        cin >> s;
        if (isLeft(s)) {
            int cnt = count(s);
            lft[cnt]++;

            // 如果差值为 0，说明即可作左边的序列也可以作为右边的序列
            if (cnt == 0) rht[0]++;
        } else if (isRight(s)) {
            int cnt = count(s);
            rht[cnt]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < maxn; ++i) ans += lft[i] * rht[i];
    printf("%lld", ans);
}