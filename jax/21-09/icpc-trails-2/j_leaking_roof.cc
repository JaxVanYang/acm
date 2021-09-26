#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505;
int h[N][N];
double ans[N][N];
bool vis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

inline double f(int x, int y) {
    return h[x][y] == 0 ? ans[x][y] : 0.0;
}

int main() {
    scanf("%d%d", &n, &m);

    // int maxV = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", h[i] + j);

            // maxV = max(maxV, h[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = m;
        }
    }

    // cout << "max = " << maxV << endl;

    // queue<pair<int, int>> q;
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pq.push(make_pair(h[i][j], make_pair(i, j)));
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (h[i][j] == maxV) {
    //             pq.push(make_pair(h[i][j], make_pair(i, j)));
    //         }
    //     }
    // }

    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        
        int x = p.second.first, y = p.second.second;

        // if (vis[x][y]) continue;
        // vis[x][y] = true;

        // cout << "x = " << x << " y = " << y << endl;

        vector<pair<int, int>> adj;

        for (int i = 0; i < 4; ++i) {
            int x_ = x + dx[i], y_ = y + dy[i];
            
            if (valid(x_, y_) && h[x_][y_] < h[x][y]) {
                adj.push_back(make_pair(x_, y_));
            }
        }

        for (auto &nex : adj) {
            int x_ = nex.first, y_ = nex.second;

            ans[x_][y_] += ans[x][y] / adj.size();

            // cout << "ans[" << x_ << "][" << y_ << "] = " << ans[x_][y_] << endl;

            // pq.push(make_pair(h[x_][y_], make_pair(x_, y_)));
        }
        // ans[x][y] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.8lf ", f(i, j));
            // printf("%.8lf ", ans[i][j]);
        }

        puts("");
    }
}