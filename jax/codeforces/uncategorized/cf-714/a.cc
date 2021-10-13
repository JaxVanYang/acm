#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
char s[maxn], t[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = (n - 1) / 2;
    if (cnt < k) {
        puts("-1");
        return;
    }

    int num = n;
    for (int i = 0; i < k; ++i) {
        a[2 * i + 1] = num--;
    }
    for (int i = 0; i < k; ++i) {
        a[2 * i] = num--;
    }
    for (int i = 2 * k; i < n; ++i) {
        a[i] = num--;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}