#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 16e6 + 5;
int n, nc;
int vals[260];
int cnts[maxn];
char s[maxn];

int main() {
    scanf("%d%d", &n, &nc);
    scanf("%s", s);
    int len = strlen(s);
    int val = 0;
    memset(vals, 0x3f, sizeof(vals));
    for (int i = 0; i < len; ++i) {
        if (vals[s[i]] == 0x3f3f3f3f) vals[s[i]] = val++;
    }
    // cout << "val = " << val << " a = " << vals['a'] << " b = " << vals['b'] << " c = " << vals['c'] << " d = " << vals['d'] << endl;
    int cnt = 0;
    for (int i = 0; i < len - n + 1; ++i) {
        int key = 0;
        for (int j = i; j < i + n; ++j) key = key * nc + vals[s[j]];    // 从左至右转换为 nc 进制数，用权重转换会 RE，可能是溢出了
        if (cnts[key] == 0) {
            ++cnt;
        }
        cnts[key] = 1;
    }
    printf("%d\n", cnt);
}