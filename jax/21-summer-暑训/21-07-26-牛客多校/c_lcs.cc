#include <bits/stdc++.h>
using namespace std;

const char el = '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    vector<vector<int>> v{{a}, {b}, {c}};
    sort(v.begin(), v.end());
    v[0].push_back(2), v[1].push_back(0), v[2].push_back(1);    // 标识与该 lcs 无关的字符串
    int n0 = v[0][0], n1 = v[1][0], n2 = v[2][0];
    if (n - n1 < n2 - n0) {
        cout << "NO" << el;
        return 0;
    }

    vector<string> sv{string(n0, 'a'), string(n1, 'a'), string(n1, 'a')};
    for (int i = n1; i < n; ++i) sv[1].push_back('x');
    for (int i = 0; i < n2 - n0; ++i) sv[0].push_back('b');
    for (int i = 0; i < n2 - n0; ++i) sv[2].push_back('b');
    for (int i = sv[0].size(); i < n; ++i) sv[0].push_back('y');
    for (int i = sv[2].size(); i < n; ++i) sv[2].push_back('z');

    do {
        if (vector<int>{a, b, c} == vector<int>{v[0][0], v[1][0], v[2][0]}) {
            cout << sv[v[1][1]] << el
                 << sv[v[2][1]] << el
                 << sv[v[0][1]] << el;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
}