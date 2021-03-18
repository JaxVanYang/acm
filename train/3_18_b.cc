#include <iostream>
using namespace std;

const int maxn = 1005;
int cnts[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int c;
        scanf("%d", &c);
        cnts[c]++;  
    }
    int ans = cnts[1];
    for (int i = 2; i <= n; ++i) ans = min(ans, cnts[i]);
    cout << ans << endl;
}