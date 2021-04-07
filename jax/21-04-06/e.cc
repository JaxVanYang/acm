#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n >> 1; ++i) s += "01";
    if (n & 1) {
        s += '0';
    }
    cout << s;
}