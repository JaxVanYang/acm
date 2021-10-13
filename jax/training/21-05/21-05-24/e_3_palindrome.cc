#include <iostream>
using namespace std;

const int maxn = 20'0050;
char s[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i / 2 & 1) {
            s[i] = 'a';
        } else {
            s[i] = 'b';
        }
    }
    s[n] = '\0';
    cout << s;
}