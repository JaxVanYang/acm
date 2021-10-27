#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int cnts[N];
ll tmp[N], ans[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        ++cnts[num];
    }

    for (int i = 1; i <= m; ++i) {
        if ((ll)i * i <= m) tmp[i * i] += (ll)cnts[i] * (cnts[i] - 1) / 2;

        for (int j = i + 1; j <= m / i; ++j) {
            tmp[i * j] += (ll)cnts[i] * cnts[j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; j += i) {
            ans[j] += tmp[i];
        }
    }

    for (int i = 1; i <= m; ++i) {
        printf("%lld ", ans[i]);
    }

    puts("");
}