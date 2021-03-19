#include <iostream>
using namespace std;
const int maxn = 105;
char s[maxn];

void no() {
    printf("No\n");
    exit(0);
}

void yes() {
    printf("Yes\n");
    exit(0);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    scanf("%s", s);
    for (int i = 1; i < n; ++i) {
        if (s[i] != '?' && s[i] == s[i - 1]) {
            no();
        }
    }
    int i = 0;
    while (i < n) {
        if (s[i] == '?') {
            int a = i - 1;
            while (i < n && s[i] == '?') ++i;
            int b = i;
            int len = b - a - 1;
            if (a < 0 || b >= n) yes();
            if (s[a] == s[b]) yes();
            if (s[a] != s[b] && len > 1) yes();
        } else {
            ++i;
        }
    }
    no();
}