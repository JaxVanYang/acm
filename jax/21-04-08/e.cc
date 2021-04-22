#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    vector<int> cnts(105);
    for (int i = 0; i < m; ++i) cnts[a[i]]++;
    int sz = 0;
    for (int i = 0; i < 105; ++i) if (cnts[i]) cnts[sz++] = cnts[i];
    auto valid = [&](int day) {
        int cnt = 0;
        for (int i = 0; i < sz; ++i) cnt += cnts[i] / day;
        return cnt >= n;
    };
    int l = 0, r = 105;
    while (l < r) {
        int mid = r - (r - l) / 2;
        if (valid(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}