#include <iostream>
using namespace std;

int main() {
    int a, b, f, k;
    cin >> a >> b >> f >> k;
    if (b < f || a - f > b || k > 1 && 2 * (a - f) > b || k > 2 && 2 * f > b) {
        puts("-1");
    } else {
        int ans = 0;
        int left = b - f;
        int cost[] = {f << 1, a - f << 1};
        for (int i = 1; i < k; ++i) {
            // cout << "i = " << i << " left = " << left << endl;
            if (left < cost[i & 1]) {
                // cout << "plus" << endl;
                ++ans;
                left = b;
            }
            left -= cost[i & 1];
            // cout << " " << left << endl;
        }
        if (left < (cost[k & 1] >> 1)) {
            // cout << "plus" << endl;
            ++ans;
        }
        printf("%d\n", ans);
    }
}