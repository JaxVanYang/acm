#include <iostream>
using namespace std;

inline int sum(int n) {
    return (n * n + 2 * n + 1) / 4;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        if (s == 1) cout << 1 << endl;
        else if (s == 2) cout << 2 << endl;
        else {
            int l = 1, r = 5000;
            while (l < r) {
                // cout << "l = " << l << " r = " << r << endl;
                int mid = l + r + 1 >> 1;
                int tmp = sum(2 * mid - 1);
                if (tmp <= s) l = mid;
                else r = mid - 1;
            }
            if (sum(2 * l - 1) == s) cout << l << endl;
            else cout << l + 1 << endl;
        }
    }
}