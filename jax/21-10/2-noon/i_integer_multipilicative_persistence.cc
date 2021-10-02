#include <iostream>
using namespace std;

int calc(int n) {
    int ret = 0;

    while (n > 9) {
        int tmp = 1;
        
        while (n) {
            tmp *= n % 10;
            n /= 10;
        }

        n = tmp;

        ++ret;
    }

    return ret;
}

void solve() {
    int n;
    scanf("%d", &n);

    printf("%d\n", calc(n));
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }
}