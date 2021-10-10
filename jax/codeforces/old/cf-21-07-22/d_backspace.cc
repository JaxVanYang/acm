#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
char s[N], t[N];
int n, m;

void solve() {
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    // printf("s = %s t = %s\n", s, t);
    int i = n - 1, j = m - 1;
    while (i >= 0) {
        // printf("i = %d j = %d\n", i, j);
        int r = i;
        while (r >= 0 && s[r] != t[j]) {
            --r;
        }
        if ((r - i) & 1) {
            i = r - 1;
        } else {
            i = r - 1;
            if (j == 0) {
                puts("YES");
                return;
            } 
            --j;
        }
    }
    puts("NO");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        solve();
    }
}