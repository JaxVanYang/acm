#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
char a[maxn], b[maxn];
char s[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        a[n] = b[n] = '\0';
        scanf("%s", s);
        // Note: 不要忘记了数字字符的引号
        if (s[0] == '0' || s[n - 1] == '0') {
            puts("NO");
            continue;
        }
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) if (s[i] == '1') ++cnt1;
        if (cnt1 & 1) {
            puts("NO");
            continue;
        }
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                a[i] = b[i] = cnt++ < cnt1 / 2 ? '(' : ')';
            } else {
                if (flag) {
                    a[i] = '(';
                    b[i] = ')';
                } else {
                    a[i] = ')';
                    b[i] = '(';
                }
                flag = !flag;
            }
        }
        puts("YES");
        printf("%s\n%s\n", a, b);
    }
}