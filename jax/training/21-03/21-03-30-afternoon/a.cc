#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
char s[maxn];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int l = 0, r = n - 1;
    int ans;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if ((i & 1) && s[i] == 'b') ++cnt0;
        else if (!(i & 1) && s[i] == 'r') ++cnt1;
    }
    ans = max(cnt0, cnt1);
    cnt0 = cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if ((i & 1) && s[i] == 'r') ++cnt0;
        else if (!(i & 1) && s[i] == 'b') ++cnt1;
    }
    ans = min(ans, max(cnt0, cnt1));
    printf("%d", ans);
}