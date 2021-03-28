#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);
    if (n & 1) printf("%d", a[n / 2]);
    else printf("%d", a[n / 2 - 1]);
}