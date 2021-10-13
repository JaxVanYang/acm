#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e6 + 10;
char s[N];

void solve() {
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        s[i] = s[i] == 'B' ? 1 : -1;
    }

    memcpy(s + n, s, n);

    int l = 0;
    while (l < n) {
        int r = l, sum = 0;

        while (r - l < n && sum >= 0) {
            sum += s[r++];
        }

        if (r - l == n) {
            printf("%d\n", l);
            return;
        }

        l = r;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}