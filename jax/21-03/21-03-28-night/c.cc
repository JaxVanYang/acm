#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 1005;
char s[maxn];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    // stack<char> stk;
    // bool flag = s[0] == '1';
    // if (n == 1 && !flag) {
    //     printf("No\n");
    //     return 0;
    // }
    // for (int i = 1; i < n; ++i) {
    //     bool newFlag = s[i] == '1';
    //     if (!(flag ^ newFlag)) {
    //         printf("No\n");
    //         return 0;
    //     }
    //     flag = newFlag;
    // }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if ((i != 0 && s[i - 1] == '1') || (i != n - 1 && s[i + 1] == '1')) {
                printf("No\n");
                return 0;
            }
        } else if ((i == 0 || s[i - 1] == '0') && (i == n - 1 || s[i + 1] == '0')) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}