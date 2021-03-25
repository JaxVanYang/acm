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

        // for (int j = 'a'; j <= 'z'; ++j) {
        //     cnts[j] += n;
        //     if (cnts[j] > len) {
        //         cnts[j] %= len;
        //         if (cnts[j] % 2 == 1) cnts[j] = len - 1;
        //         else cnts[j] = len;
        //     }
        //     ans[i] = max(ans[i], cnts[j]);
        // }
        // for (int j = 'A'; j <= 'Z'; ++j) {
        //     cnts[j] += n;
        //     if (cnts[j] > len) {
        //         cnts[j] %= len;
        //         if (cnts[j] % 2 == 1) cnts[j] = len - 1;
        //         else cnts[j] = len;
        //     }
        //     ans[i] = max(ans[i], cnts[j]);
        // }
        // cout << "i = " << i << " ans = " << ans[i] << endl;
    }
    // cout << "len = " << len << endl;
    for (int i = 0; i < 3; ++i) {
        if (ans[i] + n <= len) ans[i] += n;
        else if (n == 1) ans[i]--;
        else ans[i] = len;
        // cout << "i = " << i << " " << ans[i] << endl;
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