#include <iostream>
using namespace std;
const int maxn = 105;

int cnts[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int type;
        scanf("%d", &type);
        cnts[type]++;
    }
    for (int day = 1; day <= m / n + 1; ++day) {
        int cnt = 0;
        for (int i = 0; i < maxn; ++i) {
            cnt += cnts[i] / day;
        }
        // cout << "day = " << day << " cnt = " << cnt << endl;
        if (cnt < n) {
            printf("%d", day - 1);
            return 0;
        }
    }
}