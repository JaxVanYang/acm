#include <bits/stdc++.h>
using namespace std;

const int N = 70;
const char el = '\n';

int n, cnt, len, lens[N], sum;
bool st[N];

bool dfs(int cur, int cab, int begin) {
    if (cur == cnt) return true;
    if (cab == len) return dfs(cur + 1, 0, 0);
    int fail = 0;
    for (int i = begin; i < n; ++i) {
        if (!st[i] && cab + lens[i] <= len && lens[i] != fail) {
            st[i] = 1;
            if (dfs(cur, cab + lens[i], begin + 1)) return true;
            st[i] = 0;
            if (cab == 0 || cab + lens[i] == len) return false;
            fail = lens[i];
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i) cin >> lens[i];
        sort(lens, lens + n, greater<int>());
        sum = accumulate(lens, lens + n, 0);

        for (len = *max_element(lens, lens + n); len <= sum; ++len) {
            if (sum % len) continue;
            cnt = sum / len;
            memset(st, 0, sizeof st);
            if (dfs(0, 0, 0)) break;
        }
        cout << len << el;
    }
}