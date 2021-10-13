#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());

    int m;
    cin >> m;

    map<int, int> back;
    for (int i = 0; i < n; ++i) {
        back[a[i]]++;
    }

    while (m--) {
        int k, pos;
        cin >> k >> pos;

        map<int, int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt[b[n - 1 - i]]++;
        }

        map<int, int> mp(back.begin(), back.end());

        int minV = b[n - k];

        vector<int> ans;
        for (int i = 0; i < n && ans.size() < k; ++i) {
            if (a[i] == minV) {
                cnt[minV]--;
                ans.push_back(a[i]);
                if (cnt[minV] == 0 && ans.size() < k) {
                    auto p = cnt.find(minV);

                    while (p->second == 0) {
                        ++p;
                    }

                    minV = p->first;
                }
            } else if (cnt.count(a[i]) && cnt[a[i]] != 0) {
                if (mp[a[i]] > cnt[a[i]]) {
                    continue;
                } else {
                    cnt[a[i]]--;
                    ans.push_back(a[i]);
                }
            }
            mp[a[i]]--;
        }

        // for (auto it : ans) {
        //     cout << it << ' ';
        // }
        // cout << endl;

        cout << ans[pos - 1] << endl;
    }
}