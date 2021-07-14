#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
double a[maxn], sum[maxn];
int main() {
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", a + i);
    }
    double l = -1e6, r = 1e6, eps = 1e-5;
    while (l + eps < r) {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i] - mid;
        }
        // maxSum 是长度大于等于 f 的最大子段和
        double maxSum = -1.0, minVal = 1e10;
        for (int i = f; i <= n; ++i) {
            minVal = min(minVal, sum[i - f]);
            maxSum = max(maxSum, sum[i] - minVal);
        }
        if (maxSum >= 0) l = mid; else r = mid;
        // cout << "maxSum = " << maxSum << endl;
        // cout << "l = " << l << " r = " << r << endl;
    }
    cout << int(r * 1000) << endl;
}