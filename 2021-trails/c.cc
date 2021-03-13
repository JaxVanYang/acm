#include <iostream>
using namespace std;

int count(int n) {
    int cnt = 0;
    while (n) {
        ++cnt;
        n >>= 1;
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n - (1 << count(n) - 1) << endl;
    }
}