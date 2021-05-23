#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i * 2 <= n; ++i) {
        // cout << "w = " << n / i << endl;
        ans++;
    }
    printf("%d", ans);
}