#include <iostream>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto &ch : s) {
        if (ch == 'o') {
            ++a;
        } else {
            ++b;
        }
    }
    if (a == 0) {
        printf("YES");
        return 0;
    }
    if (b % a == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
}