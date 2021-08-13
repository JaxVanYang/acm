/* 
 *            0     1
 *            2     3
 *      4  5  6  7  8  9  10
 *            11    12
 *      13 14 15 16 17 18 19
 *            20    21
 *            22    23
 *            
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 24;
int v[N];
string ans;
const string moves = "ABCDEFGH";
const string rmoves = "FEHGBADC";

const int center[] = {6, 7, 8, 11, 12, 15, 16, 17};
const int operation[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10},
};
int opposite[8][7];

void answer() {
    for (int i = 1; i < ans.size(); ++i) cout << ans[i];
    cout << endl;
}

int count() {
    int cnt[4] = {};
    for (int i : center) {
        cnt[v[i]]++;
    }
    return *max_element(cnt + 1, cnt + 4);
}

inline int f() {
    return 8 - count();
}

void operate(const int opt[7]) {
    int tmp = v[opt[0]];
    for (int i = 0; i < 6; ++i) {
        v[opt[i]] = v[opt[i + 1]];
    }
    v[opt[6]] = tmp;
}

bool dfs(int dep) {
    if (dep < 0) return false;
    int pred = f();
    if (pred == 0) return true;
    if (pred > dep) return false;

    for (int i = 0; i < 8; ++i) {
        if (ans.back() == rmoves[i]) continue;
        operate(operation[i]);
        ans.push_back(moves[i]);
        if (dfs(dep - 1)) return true;
        ans.pop_back();
        operate(opposite[i]);
    }

    return false;
}

void solve() {
    int dep = 0;
    while (!dfs(dep)) {
        ++dep;
    }
    if (!dep) {
        cout << "No moves needed" << endl;
    } else {
        answer();
    }
    cout << v[6] << endl;
}

void init() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            opposite[i][j] = operation[i][6 - j];
        }
    }
}

clock_t startTime;
inline double getCurTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int main() {
    startTime = clock();
    init();
    while (cin >> v[0] && v[0] != 0) {
        for (int i = 1; i < N; ++i) cin >> v[i];
        ans.resize(1);
        solve();
    }
    // cout << getCurTime() << endl;
}