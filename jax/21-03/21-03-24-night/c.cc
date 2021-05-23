#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1e3 + 5;
// char s[maxn];
bool code[26];
bool st[(1 << 26) - 1];
int cnt;

int main() {
    int n;
    cin >> n;
    auto fromCode = []() {
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            ret = (ret << 1) + code[i];
        }
        return ret;
    };
    while (n--) {
        string s;
        cin >> s;
        memset(code, 0, sizeof(code));
        for (auto &ch : s) {
            code[ch - 'a'] = 1;
        }
        int res = fromCode();
        if (!st[res]) {
            ++cnt;
            st[res] = 1;
        }
    }
    cout << cnt;
}