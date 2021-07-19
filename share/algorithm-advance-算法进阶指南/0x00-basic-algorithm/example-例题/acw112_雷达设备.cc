#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1005;
pair<double, double> ranges[N];

int main() {
    int n;
    double d;
    scanf("%d%lf", &n, &d);
    for (int i = 0; i < n; ++i) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        if (y > d) {
            puts("-1");
            return 0;
        }

        // Log: made stupid mistake for writing wrong expression here
        double len = sqrt(d * d - y * y);
        double l = x - len, r = x + len;
        ranges[i] = make_pair(l, r);
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << "l = " << ranges[i].first << " r = " << ranges[i].second << endl;
    // }
    sort(ranges, ranges + n);
    double last = -1e18;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        double l = ranges[i].first, r = ranges[i].second;
        // cout << "l = " << l << " r = " << r << " last = " << last << endl;
        if (l > last) {
            ++ans;
            last = r;
        } else {
            last = min(last, r);
        }
    }
    printf("%d\n", ans);
}