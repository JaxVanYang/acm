#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline bool cmp(const string &s1, const string &s2) {
    return s1.length() < s2.length();
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 1; i < n; ++i) {
        if (a[i].find(a[i - 1]) >= a[i].length()) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (auto &each : a) cout << each << endl;
}