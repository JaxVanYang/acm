#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto &ch : s) {
        if (ch == '0') cnt0++;
        else cnt1++;
    }
    if (cnt1) putchar('1');
    for (int i = 0; i < cnt0; ++i) {
        putchar('0');
    }
}