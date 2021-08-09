#include <bits/stdc++.h>
using namespace std;
using ll = long long;

clock_t startTime = clock();

inline double curTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int main() {
    int w, n;
    cin >> w >> n;
    int half = n > 10 ? n / 2 + 2 : n / 2;
    vector<int> v(n);
    for (auto &it : v) cin >> it;
    sort(v.begin(), v.end(), greater<int>());
    vector<int> a{0};
    for (int i = 0; i < half; ++i) {
        int len = a.size();
        for (int j = 0; j < len; ++j) {
            if ((ll)v[i] + a[j] <= w) a.push_back(v[i] + a[j]);
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    vector<int> b{0};
    for (int i = half; i < n; ++i) {
        int len = b.size();
        for (int j = 0; j < len; ++j) {
            if ((ll)v[i] + b[j] <= w) b.push_back(v[i] + b[j]);
        }
    }
    sort(b.begin(), b.end(), greater<int>());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int ans = 0;
    for (int num : b) {
        if (ans == w) break;
        if ((ll)num + a[0] <= ans) break;
        int l = 0, r = a.size();
        int lmt = w - num;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] <= lmt) r = mid;
            else l = mid + 1;
        }
        if (l != a.size()) ans = max(ans, num + a[l]);
    }
    cout << ans << endl;
    // cout << curTime() << endl;
}