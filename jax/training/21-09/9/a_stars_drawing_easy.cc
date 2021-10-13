#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;
template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair
#define Sort(v) sort(v.begin(), v.end())
#define Unique(v) unique(v.begin(), v.end())
#define Lower(v, val) lower_bound(v.begin(), v.end(), val)
#define Upper(v, val) upper_bound(v.begin(), v.end(), val)
#define Reverse(v) reverse(v.begin(), v.end())

const char el = '\n';
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

const int N = 100 + 10;
char grid[N][N];
bool vis[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> (&grid[i][1]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '*') {
                u[i][j] = i;

                if (grid[i - 1][j] == '*') {
                    u[i][j] = u[i - 1][j];
                }
            }

        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '*') {
                d[i][j] = i;

                if (grid[i + 1][j] == '*') {
                    d[i][j] = d[i + 1][j];
                }
            }

        }

    }

    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (grid[i][j] == '*') {
                l[i][j] = j;

                if (grid[i][j - 1] == '*') {
                    l[i][j] = l[i][j - 1];
                }
            }

        }

    }

    for (int j = m; j >= 1; --j) {
        for (int i = 1; i <= n; ++i) {
            if (grid[i][j] == '*') {
                r[i][j] = j;

                if (grid[i][j + 1] == '*') {
                    r[i][j] = r[i][j + 1];
                }
            }

        }

    }

    // REP(i, 1, n + 1) {
    //     REP(j , 1, m + 1) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    // REP(i, 1, n + 1) {
    //     REP(j, 1, m + 1) {
    //         cout << u[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    vector<tuple<int, int, int>> ans;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '.') {
                continue;
            }

            int len = i - u[i][j];
            len = min(len, d[i][j] - i);
            len = min(len, j - l[i][j]);
            len = min(len, r[i][j] - j);

            // cout << "i = " << i << " j = " << j << endl;
            // cout << u[i][j] << ' ' << d[i][j] << ' ' << l[i][j] << ' ' << r[i][j] << endl;
            // cout << "len = " << len << endl;

            // cout << i - u[i][j] << ' ' << d[i][j] - i << ' ' << j - l[i][j] << ' ' << r[i][j] - j << endl;

            if (len <= 0) {
                continue;
            }

            ans.push_back({i, j, len});

            vis[i][j] = true;
            for (int k = 1; k <= len; ++k) {
                vis[i + k][j] = vis[i - k][j] = vis[i][j + k] = vis[i][j - k] = true;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == '*' && vis[i][j] == false) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans.size() << endl;
    
    for (auto &t : ans) {
        cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
    }
}
