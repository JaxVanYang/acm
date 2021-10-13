#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        if (n & 1) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}