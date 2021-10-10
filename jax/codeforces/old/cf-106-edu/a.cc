#include <iostream>
using namespace std;

bool valid(int k1, int k2, int cnt) {
    int a = min(k1, k2);
    int b = max(k1 - a, k2 - a);
    int c = a + b / 2;
    return c >= cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        scanf("%d%d%d", &n, &k1, &k2);
        int w, b;
        scanf("%d%d", &w, &b);
        if (valid(k1, k2, w) && valid(n - k1, n - k2, b)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}