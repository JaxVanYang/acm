#include <bits/stdc++.h>
using namespace std;

const string tar = "12345678x";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
unordered_map<char, int> posx, posy;
const char step[] = {'u', 'd', 'l', 'r'};

struct Node {
    int dis, pred, pos;
    string s, path;
};
inline bool operator<(const Node &a, const Node &b) {
    return a.dis + a.pred > b.dis + b.pred;
}

bool check(string &s) {
    string t;
    for (auto ch : s) if (ch != 'x') t.push_back(ch);

    int cnt = 0;
    for (int i = 0; i < t.size(); ++i) for (int j = i + 1; j < t.size(); ++j) if (t[i] > t[j]) ++cnt;
    return cnt % 2 == 0;
}

inline pair<int, int> trans(int pos) {
    return {pos / 3, pos % 3};
}
inline int trans(int x, int y) {
    return x * 3 + y;
}
inline bool valid(int x, int y) {
    return 0 <= x && x < 3 && 0 <= y && y < 3;
}

void init() {
    for (int i = 0; i < 8; ++i) {
        auto [x, y] = trans(i);
        posx[tar[i]] = x;
        posy[tar[i]] = y;
    }
}

int f(string &s) {
    int ret = 0;
    for (int i = 0; i < 9; ++i) if (s[i] != 'x') {
        auto [x, y] = trans(i);
        ret += abs(x - posx[s[i]]) + abs(y - posy[s[i]]);
    }
    return ret;
}

int main() {
    init();
    priority_queue<Node> pq;
    unordered_set<string> st;
    
    Node node{0};
    node.s.resize(9);
    for (int i = 0; i < 9; ++i) {
        cin >> node.s[i];
        if (node.s[i] == 'x') node.pos = i;
    }

    if (!check(node.s)) {
        cout << "unsolvable" << endl;
        return 0;
    }

    pq.push(node);
    while (pq.size()) {
        Node cur = pq.top();
        if (cur.s == tar) {
            cout << cur.path << endl;
            return 0;
        }
        pq.pop();
        st.insert(cur.s);
        auto [x, y] = trans(cur.pos);
        for (int i = 0; i < 4; ++i) {
            int x_ = x + dx[i], y_ = y + dy[i];
            if (valid(x_, y_)) {
                int pos = trans(x_, y_);
                Node nex = cur;
                swap(nex.s[pos], nex.s[nex.pos]);
                if (st.count(nex.s)) continue;
                nex.pos = pos;
                nex.dis++;
                nex.pred = f(nex.s);
                nex.path.push_back(step[i]);
                pq.push(nex);
            }
        }
    }
}