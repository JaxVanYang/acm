// 让大的尽量小，大的尽量小，考虑二进制的形式
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int val[2] = {1 << n};
        for (int i = 1; i < n / 2; ++i) {
            val[0] += 1 << i;
        }
        for (int i = n / 2; i < n; ++i) {
            val[1] += 1 << i;
        }
        printf("%d\n", val[0] - val[1]);
    }
}