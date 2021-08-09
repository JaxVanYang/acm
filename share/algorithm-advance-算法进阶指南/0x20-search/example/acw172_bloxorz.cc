#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y, lie; // 0 表示立在地面上，1 表示横置在地面上，2 表示纵向防止在地面上，x，y 均为左上角的方块坐标
};

ostream &operator<<(ostream &out, Node &node) {
    return out << node.x << ' '  << node.y << ' ' << node.lie;
}

const int N = 510;
int n, m, d[N][N][3];
Node st, ed;
char grid[N][N];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

inline bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool valid(Node &node) {
    auto [x, y, lie] = node;
    if (!valid(x, y)) return false;
    if (grid[x][y] == '#') return false;
    if (lie == 0 && grid[x][y] == 'E') return false;
    if (lie == 1 && grid[x][y + 1] == '#') return false;
    if (lie == 2 && (x + 1 >= n || grid[x + 1][y] == '#')) return false;
    return true;
}

const int next_x[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
const int next_y[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
const int next_lie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};

void parse_input() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'O') {
        ed = Node{i, j, 0};
        break;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == 'X') {
        for (int k = 1; k <= 2; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (valid(x, y) && grid[x][y] == 'X') {
                st = Node{i, j, k};
                return;
            }
        }
        st = Node{i, j, 0};
        return;
    }
}

int bfs() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 3; ++k) d[i][j][k] = -1;
    queue<Node> q;
    d[st.x][st.y][st.lie] = 0;
    q.push(st);
    while (q.size()) {
        auto [x, y, lie] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            Node nxt{x + next_x[lie][i], y + next_y[lie][i], next_lie[lie][i]};
            if (!valid(nxt)) continue;
            if (d[nxt.x][nxt.y][nxt.lie] == -1) {
                if (nxt.x == ed.x && nxt.y == ed.y && nxt.lie == ed.lie) return d[x][y][lie] + 1;
                d[nxt.x][nxt.y][nxt.lie] = d[x][y][lie] + 1;
                q.push(nxt);
            }
        }
    }
    return -1;
}


int main() {
    while (cin >> n >> m && n) {
        for (int i = 0; i < n; ++i) cin >> grid[i];
        parse_input();
        // cout << st << endl << ed << endl;
        int ans = bfs();
        if (ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
}