#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int w[maxn], h[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d%d", w + i, h + i);
    h[0] = max(h[0], w[0]);
    for (int i = 1; i < n; ++i) {
        if (h[i - 1] < min(h[i], w[i])) {
            puts("NO");
            return 0;
        }
        if (h[i - 1] < max(h[i], w[i])) {
            h[i] = min(h[i], w[i]);
        } else {
            h[i] = max(h[i], w[i]);
        }
    }
    puts("YES");
}