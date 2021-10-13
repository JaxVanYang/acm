#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn], t[maxn];

int main() {
    scanf("%s%s", s, t);
    int len1 = strlen(s), len2 = strlen(t);
    int cnt = 0;
    for (int i = 0; i < min(len1, len2); ++i) {
        if (s[len1 - 1 - i] != t[len2 - 1 - i]) break;
        ++cnt;
    }
    cout << len1 + len2 - 2 * cnt << endl;
}