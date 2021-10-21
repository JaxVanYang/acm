#include <bits/stdc++.h>
using namespace std;

template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}

const int N = 45;
int a[N];

vector<int> divs(int val) {
    vector<int> ret;
    // cout << "val = " << val << endl;

    int i;
    for (i = 1; i < val / i; ++i) {
        if (val % i == 0) {
            // cout << "i = " << i << endl;
            ret.push_back(i);
            ret.push_back(val / i);
        }
    }
    if (i * i == val) {
        ret.push_back(i);
    }

    return ret;
}

void solve() {
    int n;
    read(n);
    int half = n / 2;

    for (int i = 0; i < n; ++i) {
        read(a[i]);
    }

    int ans = -1;

    for (int i = 0; i < n; ++i) {
        int minv = a[i], same = 0;
        vector<int> candi;

        for (int j = 0; j < n; ++j) {
            if (a[j] == minv) {
                ++same;
            } else if (a[j] > a[i]) {
                candi.push_back(a[j] - a[i]);
            }
        }

        if (same >= half) {
            ans = -1;
            break;
        }

        if (same + candi.size() < half) continue;

        map<int, int> mp;
        for (int val : candi) {
            for (int d : divs(val)) {
                // cout << "d = " << d << endl;
                mp[d]++;
            }
            // cout << endl;
        }

        auto iter = mp.rbegin();
        while (iter != mp.rend()) {
            auto [d, cnt] = *iter;
            // cout << "d = " << d << " cnt = " << cnt << endl;

            if (cnt + same >= half) {
                ans = max(ans, d);
                break;
            }

            ++iter;
        }
    }

    printf("%d\n", ans);
}

int main() {
    int t;
    read(t);

    while (t--) {
        solve();
    }
}