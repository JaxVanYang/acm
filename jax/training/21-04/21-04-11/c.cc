#include <iostream>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        // cout << "cur = " << cur << endl;
        if (cur + a[i] >= m) {
            printf("%d ", 1 + (a[i] - m + cur) / m);
            cur = (a[i] - m + cur) % m;
        } else {
            printf("0 ");
            cur += a[i];
        }
    }
}