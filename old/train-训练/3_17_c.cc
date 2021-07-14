#include <iostream>
using namespace std;

int cnt(int h, int m) {
    if (h >= 20) return 0;
    return (20 - h) * 60 - m;
}

int main() {
    int hh, mm;
    cin >> hh >> mm;
    // hungery, increse per minute, cost, decrease
    // cout << "hh = " << hh << " mm = " << mm << endl;
    int h, d, c, n;
    cin >> h >> d >> c >> n;
    double ans;
    int time = cnt(hh, mm);
    // cout << "time = " << time << endl;
    int num = h % n ? h / n + 1 : h / n;
    if (time == 0) {
        ans = 0.8 * num * c;
    } else {
        ans = num * c;
        h += time * d;
        num = h % n ? h / n + 1 : h / n;
        ans = min(ans, 0.8 * num * c);
    }
    printf("%.4llf\n", ans);
}