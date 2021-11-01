#include <cstdio>
#include <iostream>

using namespace std;

const int N = 4e5 + 10;
typedef long long LL;
int a[N], n, m, ans[N];

int main() {
    cin >> n >> m;
    a[0] = 0, a[n + 1] = m;
    for (int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
    int flag = 1;
    ans[0] = 0;
    for (int i = 1 ; i <= n + 1 ; i++) {
        ans[i] = ans[i - 1] + flag * (a[i] - a[i - 1]);
        flag ^= 1;
    }
    int cnt = ans[n + 1];
    for (int i = 1 ; i <= n + 1 ; i++) {
        cnt = max(cnt, ans[i] - 1 + m - a[i] - (ans[n + 1] - ans[i]));
    }
    printf("%d\n", cnt);
    return 0;
}