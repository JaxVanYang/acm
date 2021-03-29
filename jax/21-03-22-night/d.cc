#include <iostream>
using namespace std;
int times[105];

int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        int h, m;
        cin >> h >> m;
        times[i] = h * 60 + m;
    }
    if (times[0] > s) {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i) {
        if (times[i] - times[i - 1] > 2 * s + 1) {
            int ans = times[i - 1] + s + 1;
            int x = ans / 60, y = ans % 60;
            cout << x << ' ' << y << endl;
            return 0;
        }
    }
    int ans = times[n - 1] + s + 1;
    cout << ans / 60 << ' ' << ans % 60 << endl;
}