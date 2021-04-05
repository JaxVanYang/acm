#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int minV = 2e9;
    for (int i = 0; i < n; ++i) minV = min(minV, a[i]);
    minV = (minV / n) * n;
    
    for (int i = 0; i < n; ++i) a[i] -= minV;
    while (1) for (int i = 0; i < n; ++i) {
        if (a[i] <= i) {
            printf("%d\n", i + 1);
            return 0;
        }
        a[i] -= n;
    }
}