#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    double a = y * log(x), b = x * log(y);
    if (abs(a - b) < 1e-8) {
        cout << "=" << endl;
    } else if (a < b) {
        cout << "<" << endl;
    } else {
        cout << ">" << endl;
    }
}