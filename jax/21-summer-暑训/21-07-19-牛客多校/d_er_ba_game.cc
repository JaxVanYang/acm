#include <iostream>
using namespace std;

int cmp(int a1, int b1, int a2, int b2) {
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if (a1 == 2 && b1 == 8) {
        if (a2 == 2 && b2 == 8) return 0;
        return 1;
    }
    if (a2 == 2 && b2 == 8) return -1;
    if (a1 == b1 && a2 != b2) return 1;
    if (a1 != b1 && a2 == b2) return -1;
    int x = (a1 + b1) % 10, y = (a2 + b2) % 10;
    if (x > y) return 1;
    if (x < y) return -1;
    return b1 - b2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int res = cmp(a1, b1, a2, b2);
        if (res == 0) {
            cout << "tie" << endl;
        } else if (res < 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }
}