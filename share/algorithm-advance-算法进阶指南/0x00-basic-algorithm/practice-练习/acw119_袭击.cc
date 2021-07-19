#include <iostream>
#include <cmath>
#include <algorithm>

const int N = 1e5 + 10;
const double INF = 1e18;
double max_dis = INF;
const double eps = 1e-6;
struct Coor {
    double x, y;
    bool type;
    double dis(const Coor &b) {
        if (type == b.type) return max_dis;
        double x_dis = x - b.x, y_dis = y - b.y;
        return sqrt(x_dis * x_dis + y_dis * y_dis);
    }
    bool operator<(const Coor &b) {
        return x < b.x;
    }
} ps[2 * N];

double calc(int l, int r) {
    // printf("l = %d r = %d\n", l, r);
    if (r - l < 2) return max_dis;
    if (r - l == 2) return ps[l].dis(ps[l + 1]);
    int mid = l + r >> 1;
    // Trick: 动态更新全局最小距离，可以减少大量比较，特别是对于全都相同的点可以优化到 O(nlog(n))
    // 对于全都相同的点，优化之前为 O(n^2log(n))
    double ret = max_dis = std::min(calc(l, mid), calc(mid, r));
    // printf("ret = %lf\n", ret);
    for (int i = mid - 1; i >= l; --i) {
        // Trick: 当距离差和当前最小值差距很小的时候可以直接跳过，减少复杂度
        if (ps[mid].x - ps[i].x + eps > ret) break;
        for (int j = mid; j < r; ++j) {
            if (ps[j].x - ps[i].x + eps > ret) break;
            ret = max_dis = std::min(ret, ps[i].dis(ps[j]));
        }
    }
    return ret;
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &ps[i].x, &ps[i].y);
        ps[i].type = false;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &ps[n + i].x, &ps[n + i].y);
        ps[i].type = true;
    }
    std::sort(ps, ps + 2 * n);
    max_dis = ps[0].dis(ps[2 * n - 1]);
    // puts("sorted");
    printf("%.3lf\n", calc(0, 2 * n));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        // Note：多组数据需要重置最大距离
        max_dis = INF;
        solve();
    }
}