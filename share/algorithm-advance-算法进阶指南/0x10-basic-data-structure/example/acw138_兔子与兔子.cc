#include <iostream>
#include <cstring>

using ull = unsigned long long;

const int N = 1e6 + 10;
const int P = 131;
char s[N];
ull f[N], p[N];

int main() {
    scanf("%s", s + 1);
    p[0] = 1;
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * P + s[i] - 'a';
        p[i] = p[i - 1] * P;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (f[r1] - f[l1 - 1] * p[r1 - l1 + 1] == f[r2] - f[l2 - 1] * p[r2 - l2 + 1]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}