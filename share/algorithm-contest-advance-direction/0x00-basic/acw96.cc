#include <iostream>
#include <cstring>
using namespace std;
int d[13], f[13];
int main() {
    memset(d, 0x3f, sizeof(d));
    memset(f, 0x3f, sizeof(f));
    d[0] = 0, f[0] = 0;
    for (int i = 1; i <= 12; ++i) d[i] = 2 * d[i - 1] + 1;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
        }
    }
    for (int i = 1; i <= 12; ++i) {
        cout << f[i] << endl;
    }
}