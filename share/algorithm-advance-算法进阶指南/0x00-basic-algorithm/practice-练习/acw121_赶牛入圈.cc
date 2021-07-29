#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

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

const char el = '\n';
const int N = 500 + 10;
int grid[N][N];
int c, n;
vi x, y, xv, yv;

void discrete(vi &v) {
    Sort(v);
    v.resize(Unique(v) - v.begin());
}

// return the index of the largest element that is not greater than val
int query(vi &v, int val) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (v[mid] <= val) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l + 1;   // Note: plus 1 here
}

template<typename T>
void print(T &v) {
    for (auto val : v) {
        cout << val << ' ';
    }
    cout << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> n;
    x.resize(n), y.resize(n);
    REP(i, 0, n) {
        cin >> x[i] >> y[i];
    }
    xv.assign(x.begin(), x.end());
    discrete(xv);
    
    yv.assign(y.begin(), y.end());
    discrete(yv);

    // print(xv);
    // print(yv);

    REP(i, 0, n) {
        grid[query(xv, x[i])][query(yv, y[i])]++;
    }

    REP(i, 1, xv.size() + 1) {
        REP(j, 1, yv.size() + 1) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }

    // REP(i, 0, xv.size() + 1) {
    //     REP(j, 0, yv.size() + 1) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << el;
    // }

    int ans = INT32_MAX;
    REP(i, 1, xv.size() + 1) {
        REP(j, 1, yv.size() + 1) {
            int l = 1, r = max(xv.back() - xv[i - 1], yv.back() - yv[j - 1]) + 1;
            // cout << "i = " << i << " j = " << j << " l = " << l << " r = " << r << el;
            while (l < r) {
                int mid = l + r >> 1;
                // cout << "mid = " << mid << el;
                int xi = query(xv, xv[i - 1] + mid - 1), yi = query(yv, yv[j - 1] + mid - 1);
                int val = grid[xi][yi] - grid[xi][j - 1] - grid[i - 1][yi] + grid[i - 1][j - 1];
                if (val >= c) r = mid;
                else l = mid + 1;
            }
            int xi = query(xv, xv[i - 1] + l - 1), yi = query(yv, yv[j - 1] + l - 1);
            int val = grid[xi][yi] - grid[xi][j - 1] - grid[i - 1][yi] + grid[i - 1][j - 1];

            // cout << "l = " << l << " r = " << r << el;
            // cout << i << ", " << j << " to " << xi << ", " << yi << " val = " << val << el;
            if (val >= c) ans = min(ans, l);
        }
    }

    cout << ans << el;
}
