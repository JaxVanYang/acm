#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 3e5 + 5;
char a[maxn], b[maxn];
// int sumA[2][maxn], sumB[2][maxn];
int sum[maxn];
bool flags[maxn];

int main() {
    int t;
    scanf("%d", &t);
AGAIN:
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s%s", a, b);
        if ((n & 1) && a[n - 1] != b[n - 1]) {
            puts("NO");
            continue;
        }
        if (n & 1) --n;

        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i - 1] - '0';
            flags[i] = sum[i] * 2 == i;
        }

        int stat = 0;
        for (int i = n - 2; i >= 0; i -= 2) {
            if (stat) {
                a[i] = a[i] == '0' ? '1' : '0';
                a[i + 1] = a[i + 1] == '0' ? '1' : '0';
            }
            if (a[i] == b[i] && a[i + 1] == b[i + 1]) continue;
            if (a[i] != b[i] && a[i + 1] != b[i + 1] && flags[i + 2]) {
                // cout << "yes" << endl;
                stat ^= 1;
            } else {
                puts("NO");
                goto AGAIN;
            }
        }
        puts("YES");
    }
}