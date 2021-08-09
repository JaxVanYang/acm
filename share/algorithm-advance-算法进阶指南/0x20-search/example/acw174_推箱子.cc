#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m;
char grid[N][N];
int xs, ys, xb, yb, xt, yt;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char man[] = {'n', 's', 'w', 'e'};
const char box[] = {'N', 'S', 'W', 'E'};

struct Node {
    int x, y, dir;
};
int fbox[N][N][4], fman[N][N][4];
Node pre[N][N][4];

void parse_input() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'S') {
        xs = i, ys = j;
        break;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'B') {
        xb = i, yb = j;
        break;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'T') {
        xt = i, yt = j;
        return;
    }
}

void reset() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 4; ++k) {
        fbox[i][j][k] = fman[i][j][k] = -1;
    }
}

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] != '#';
}

int expand(int xs, int ys, int xt, int yt, int xb, int yb) {
    char ch = grid[xb][yb];
    grid[xb][yb] = '#';

    queue<pair<int, int>> q;
    set<pair<int, int>> st;
    q.push({xs, ys});
    st.insert({xs, ys});
    int dis = 0;
    while (q.size()) {
        int len = q.size();
        while (len--) {
            auto [x, y] = q.front();
            q.pop();

            if (x == xt && y == yt) {
                grid[xb][yb] = ch;
                return dis;
            }

            for (int i = 0; i < 4; ++i) {
                auto nex = make_pair(x + dx[i], y + dy[i]);
                if (!st.count(nex) && valid(nex.first, nex.second)) {
                    q.push(nex);
                    st.insert(nex);
                }
            }
        }
        
        ++dis;
    }

    grid[xb][yb] = ch;
    return -1;
}

void init(queue<Node> &q) {
    memset(pre, 0, sizeof pre);
    for (int i = 0; i < 4; ++i) {
        int x = xb - dx[i], y = yb - dy[i];
        if (valid(x, y)) {
            int dis = expand(xs, ys, x, y, xb, yb);
            if (dis != -1) {
                q.push(Node{xb, yb, i});
                fbox[xb][yb][i] = 0;
                fman[xb][yb][i] = dis;
                pre[xb][yb][i].x = -1;
            }
        }
    }
}

vector<char> Path(int xs, int ys, int xt, int yt, int xb, int yb) {
    vector<char> ret;
    char ch = grid[xb][yb];
    grid[xb][yb] = '#';
    queue<pair<pair<int, int>, vector<char>>> q;
    set<pair<int, int>> st;
    q.push({{xs, ys}, {}});
    st.insert({xs, ys});
    while (q.size()) {
        auto [cur, path] = q.front();
        q.pop();
        if (cur.first == xt && cur.second == yt) {
            ret = path;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            auto nex = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (valid(nex.first, nex.second) && !st.count(nex)) {
                st.insert(nex);
                path.push_back(man[i]);
                q.push({nex, path});
                path.pop_back();
            }
        }
    }
    grid[xb][yb] = ch;
    return ret;
}

void answer(int dir) {
    vector<vector<char>> ans;

    Node cur = {xt, yt, dir};
    while (true) {
        Node &prev = pre[cur.x][cur.y][cur.dir];
        if (prev.x == -1) break;
        vector<char> path;
        if (cur.dir != prev.dir) {
            path = Path(
                prev.x - dx[prev.dir], prev.y - dy[prev.dir],
                prev.x - dx[cur.dir], prev.y - dy[cur.dir],
                prev.x, prev.y
            );
        }
        path.push_back(box[cur.dir]);
        ans.push_back(path);

        cur = prev;
    }

    ans.push_back(Path(xs, ys, xb - dx[cur.dir], yb - dy[cur.dir], xb, yb));

    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        for (auto ch : *it) cout << ch;
    }
    cout << endl;
}

void solve() {
    queue<Node> q;
    init(q);
    int dir = -1, bdis = INT32_MAX, mdis = bdis;
    while (q.size()) {
        Node cur = q.front();
        q.pop();
        if (cur.x == xt && cur.y == yt) {
            dir = cur.dir;
            bdis = fbox[cur.x][cur.y][cur.dir];
            mdis = fman[cur.x][cur.y][cur.dir];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            Node nex = Node{cur.x + dx[i], cur.y + dy[i], i};
            if (valid(nex.x, nex.y)) {
                int dis = expand(cur.x - dx[cur.dir], cur.y - dy[cur.dir], cur.x - dx[i], cur.y - dy[i], cur.x, cur.y);
                if (dis != -1) {
                    if (fbox[nex.x][nex.y][i] == -1) q.push(nex);
                    if (fman[nex.x][nex.y][i] == -1 || (fbox[cur.x][cur.y][cur.dir] + 1 == fbox[nex.x][nex.y][i] && fman[nex.x][nex.y][i] > fman[cur.x][cur.y][cur.dir] + dis + 1)) {
                        fbox[nex.x][nex.y][i] = fbox[cur.x][cur.y][cur.dir] + 1;
                        fman[nex.x][nex.y][i] = fman[cur.x][cur.y][cur.dir] + dis + 1;
                        pre[nex.x][nex.y][i] = cur;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 4; ++i) if (
        fbox[xt][yt][i] != -1 && (fbox[xt][yt][i] < bdis || fbox[xt][yt][i] == bdis && fman[xt][yt][i] < mdis)
    ) {
        bdis = fbox[xt][yt][i];
        mdis = fman[xt][yt][i];
        dir = i;
    }
    if (dir == -1) {
        cout << "Impossible." << endl;
        return;
    }
    answer(dir);
}

int main() {
    for (int i = 1; cin >> n >> m && n; ++i) {
        for (int i = 0; i < n; ++i) cin >> grid[i];
        parse_input();
        reset();
        cout << "Maze #" << i << endl;
        solve();
        cout << endl;
    }
}