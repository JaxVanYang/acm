#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[11];
        scanf("%s", s);
        int ans = 10;
        int a[2] = {0, 0}, b[] = {0, 0};
        for (int i = 0; i < 10; ++i) {
            int a_lft = 4 - i / 2;
            int b_lft = 5 - (i + 1) / 2;
            if (i & 1) {
                if (s[i] == '1') b[0]++;
                else if (s[i] == '?') b[1]++;
            } else {
                if (s[i] == '1') a[0]++;
                else if (s[i] == '?') a[1]++;
            }
            // printf("a[0] = %d a[1] = %d b[0] = %d b[1] = %d\n", a[0], a[1], b[0], b[1]);
            if (a[0] + a[1] > b[0] + b_lft) {
                ans = i + 1;
                break;
            }
            if (b[0] + b[1] > a[0] + a_lft) {
                ans = i + 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
}