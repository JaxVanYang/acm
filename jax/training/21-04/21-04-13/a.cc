#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1005;
int a[maxn], cnts[maxn];
int n;

void solve(int i) {
    memset(cnts, 0, sizeof(cnts));
    int p = i;
    while (cnts[p] != 1) {
        cnts[p]++;
        p = a[p];
    }
    printf("%d ", p);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        solve(i);
    }
}