#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int a[maxn];
// int lCnt[maxn], rCnt[maxn];
int main() {
    int n, v, p;
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (a[i] == v) {
            p = i;
        }
    }
    unordered_map<int, int> lCnt, rCnt;
    lCnt[0] = rCnt[0] = 1;
    int cnt = 0, minCnt = 0, maxCnt = 0;    // 注意最大最小值初值的选取
    for (int i = p - 1; i >= 0; --i) {
        if (a[i] < v) {
            cnt++;
        } else {
            cnt--;
        }
        minCnt = min(minCnt, cnt);
        maxCnt = max(maxCnt, cnt);
        lCnt[cnt]++;
    }
    cnt = 0;
    for (int i = p + 1; i < n; ++i) {
        if (a[i] > v) {
            ++cnt;
        } else {
            --cnt;
        }
        rCnt[cnt]++;
    }
    ll ans = 0;
    for (int i = minCnt; i <= maxCnt; ++i) {
        ans += (ll)lCnt[i] * rCnt[i];
    }
    printf("%lld\n", ans);
}