#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
int a[14], b[14];

ll calc(int p) {
    memcpy(b, a, sizeof(a));
    int cnt = b[p];
    b[p] = 0;
    for (int i = 0; i < 14; ++i) b[i] += cnt / 14;

    cnt %= 14;
    for (int i = 1; i <= cnt; ++i) b[(p + i) % 14]++;
    
    ll ret = 0;
    for (int i = 0; i < 14; ++i) if (b[i] % 2 == 0) ret += b[i];
    return ret;
}

int main() {
    for (int i = 0; i < 14; ++i) scanf("%d", a + i);
    ll ans = 0;
    for (int i = 0; i < 14; ++i) {
        ans = max(ans, calc(i));
    }
    printf("%lld", ans);
}