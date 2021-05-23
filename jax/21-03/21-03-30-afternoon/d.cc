#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

int a[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    ll ans = 0;
    int l = 0, r = 1;
    ll sum = a[0];
    deque<int> queMin{a[0]}, queMax{a[0]};
    while (l < n) {
        while (r < n) {
            if (queMax.size() && max(a[r], queMax.front()) - min(a[r], queMin.front()) > m) break;
            while (queMax.size() && a[r] > queMax.back()) queMax.pop_back();
            queMax.push_back(a[r]);
            while (queMin.size() && a[r] < queMin.back()) queMin.pop_back();
            queMin.push_back(a[r]);
            sum += a[r++];
        }
        ans = max(ans, sum);
        if (queMin.front() == a[l]) queMin.pop_front();
        if (queMax.front() == a[l]) queMax.pop_front();
        sum -= a[l];
        ++l;
    }
    printf("%lld", ans);
}