#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
char s[maxn];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 2e9;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'R' && s[i] == 'L') {
            ans = min(ans, a[i] - a[i - 1] >> 1);
        }
    }
    if (ans == 2e9) {
        ans = -1;
    }
    printf("%d\n", ans);
}