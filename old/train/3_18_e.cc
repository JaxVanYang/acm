#include <iostream>
#include <set>
using namespace std;

char grid[51][51];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
    set<int> rows, cols;
    // 遍历每一行
    for (int i = 0; i < n; ++i) {
        set<int> r, c;
        int cnt = 0;
        // 找出该行需要的列
        for (int j = 0; j < m; ++j) if (grid[i][j] == '#') {
            grid[i][j] = '.';
            ++cnt;
            // 如果这行或这列已经被使用说明不行
            if (rows.count(i) || cols.count(j)) {
                cout << "No" << endl;
                return 0;
            }
            // 加入到这次需要的行列集合中
            r.insert(i), c.insert(j);
        }
        // for (auto r_ : r) rows.insert(r_);  // 加入到已使用的里面
        for (auto c_ : c) { // 遍历这次使用的列
            // 找出这些列还需要的行
            for (int r_ = i + 1; r_ < n; ++r_) if (grid[r_][c_] == '#') {
                // 用过说明不行
                if (rows.count(r_)) {
                    cout << "No" << endl;
                    return 0;
                }
                r.insert(r_);
                grid[r_][c_] = '.';
                ++cnt;
            }
        }
        // 不能覆盖所有交集也不行
        if (cnt != r.size() * c.size()) {
            cout << "No" << endl;
            return 0;
        }
        for (auto r_ : r) rows.insert(r_);
        for (auto c_ : c) cols.insert(c_);
    }
    cout << "Yes" << endl;
}