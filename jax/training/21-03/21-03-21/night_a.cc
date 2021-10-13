#include <iostream>
#include <vector>
#include <cstring>
#include <cstring>
using namespace std;

const int maxn = 5005;
char s[maxn];

int main() {
    scanf("%s", s);
    int len = strlen(s);
    int a = 0, b = 0, c = 0;
    char ch;
    for (int i = 1; i < len; ++i) {
        if (s[i - 1] > s[i]) {
            printf("NO");
            return 0;
        }
    }
    int i = 0;
    while (i < len && s[i] =='a') ++i, ++a;
    // if (i < len && s == 0) {
    //     ch = s[i];
    //     while (i < len && s[i] == ch) ++i;
    // }
    while (i < len && s[i] == 'b') ++i, ++b;
    // if (i < len && s == 0) {
    //     ch = s[i];
    //     while (i < len && s[i] == ch) ++i;
    // }
    // while (i < len && s[i] != 'c') ++i;
    while (i < len && s[i] == 'c') ++i, ++c;
    if (a == 0 || b == 0) { printf("NO"); return 0; }
    if (c == a || c == b) {
        printf("YES");
    } else {
        printf("NO");
    }
}