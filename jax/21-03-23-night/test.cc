#include <iostream>
using namespace std;

int main() {
    int n = 50;
    int h = 1000;
    cout << 1 << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << h << ' ';
            if (h) h = 0; else h = 1000;
        }
        cout << endl;
    }
}