#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a < b) swap(a, b);
    scanf("%s", s);
    int ans = 0, pre = 0;
    int i = 0;
    while (i < n) {
        while (i < n && s[i] == '*') ++i;
        int l = i;
        while (i < n && s[i] == '.') ++i;
        int len = i - l;
        if (a < b) swap(a, b);
        if ((len + 1) / 2 >= a) {
            ans += a;
            a = 0;
        } else {
            ans += (len + 1) / 2;
            a -= (len + 1) / 2;
        }
        if (len / 2 >= b) {
            ans += b;
            b = 0;
        } else {
            ans += len / 2;
            b -= len / 2;
        }
        if (a == 0 && b == 0) break;
    }
    printf("%d", ans);
}