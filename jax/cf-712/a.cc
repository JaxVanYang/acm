#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        int p = 0;
        while (p < n && s[p] == 'a') ++p;
        if (p == n) {
            puts("NO");
            continue;
        } else {
            puts("YES");
            for (int i = 0; i < n - p; ++i) {
                printf("%c", s[i]);
            }
            putchar('a');
            for (int i = n - p; i < n; ++i) {
                printf("%c", s[i]);
            }
            puts("");
        }
    }
}