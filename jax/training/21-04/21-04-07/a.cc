#include <iostream>
using namespace std;
const int maxn = 1005;
int a[maxn];
int b[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int cnt = 0;
    for (int i = 0; i < n;) {
        int r = i + 1;
        while (r < n && a[r] != 1) ++r;
        b[cnt++] = r - i;
        i = r;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) cout << b[i] << ' ';
}