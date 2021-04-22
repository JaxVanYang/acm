#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int a[105];
    NEXT:
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        if (a[0] != a[1] && a[0] != a[2]) {
            puts("1");
            goto NEXT;
        }
        for (int i = 0; i < n; ++i) if (a[i] != a[0]) {
            printf("%d\n", i + 1);
            goto NEXT;
        }
    }
}