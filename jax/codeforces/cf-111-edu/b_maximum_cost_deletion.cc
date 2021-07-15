#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
char s[N];

int count(int n) {
    char ch = s[0];
    int ret = 0;
    int i = 0;
    while (i < n) {
        ++ret;
        while (i < n && s[i] == ch) {
            ++i;
        }
        ch = (ch == '0' ? '1' : '0');
        // ++i;
    }
    return ret;
}

int calc(int cnt) {
    if (cnt == 0) return 0;
    if (cnt == 1) return 1;
    if (cnt == 2) return 2;
    // if (cnt & 1) return cnt / 2 + 1;
    // return cnt / 2 + 1;
    return calc(cnt - 2) + 1;
}

int main() {
    // scanf("%s", s);
    // cout << "count = " << count(strlen(s)) << endl;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s);
        int ans = 0;
        if (b >= 0) {
            ans = a * n + n * b;
        } else {
            int cnt = count(n);
            // cout << "cnt = " << cnt << endl;
            ans = a * n + calc(cnt) * b;
        }
        printf("%d\n", ans);
    }
}