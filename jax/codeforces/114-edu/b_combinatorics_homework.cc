#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int c[3], m;
        for (int i = 0; i < 3; ++i) {
            scanf("%d", c + i);
        }
        scanf("%d", &m);

        sort(c, c + 3);

        int minV = max(0, c[2] - 1 - c[0] - c[1]);
        int maxV = accumulate(c, c + 3, 0) - 3;

        // cout << "minV = " << minV << " maxV = " << maxV << endl;

        if (minV <= m && m <= maxV) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}