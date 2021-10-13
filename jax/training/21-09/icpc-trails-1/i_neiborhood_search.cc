#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll p[N], len = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    string s;
    getline(cin, s);

    stringstream ss(s);
    ll val;
    while (ss >> val) {
        p[len++] = val;
    }

    ll a;
    cin >> a;

    ll r;
    cin >> r;

    // sort(p, p + len);

    vector<ll> ans;

    for (int i = 0; i < len; ++i) {
        if (a - r <= p[i] && p[i] <= a + r) {
            ans.push_back(p[i]);
        }
    }

    sort(ans.begin(), ans.end(), greater<>());

    for (auto it : ans) {
        cout << it << ' ';
    }
}