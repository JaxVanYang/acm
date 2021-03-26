#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn];
int cnts[256];
int ans[3];

int main() {
    int n;
    scanf("%d", &n);
    int len;
    for (int i = 0; i < 3; ++i) {
        scanf("%s", s);
        len = strlen(s);
        memset(cnts, 0, sizeof(cnts));
        for (int j = 0; j < strlen(s); ++j) {
            cnts[s[j]]++;
            ans[i] = max(ans[i], cnts[s[j]]);
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (ans[i] + n <= len) ans[i] += n; // 总有办法构造出来
        else if (n == 1) ans[i]--;  // 注意 n 为 1 的情况
        else ans[i] = len;
    }
    if (ans[0] > ans[1] && ans[0] > ans[2]) {
        printf("Kuro");
    } else if (ans[1] > ans[0] && ans[1] > ans[2]) {
        printf("Shiro");
    } else if (ans[2] > ans[0] && ans[2] > ans[1]) {
        printf("Katie");
    } else {
        printf("Draw");
    }
}