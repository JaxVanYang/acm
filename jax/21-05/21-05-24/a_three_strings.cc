#include <iostream>
using namespace std;

bool valid(string &a, string &b, string &c) {
    int n = a.length();
    for (int i = 0; i < n; ++i) {
        if (a[i] != c[i] && b[i] != c[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        if (valid(a, b, c)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}