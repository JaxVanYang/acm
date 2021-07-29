#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if ((n + m) & 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}