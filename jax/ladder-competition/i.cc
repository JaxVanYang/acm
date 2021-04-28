#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 5;

queue<char> q[105];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            q[i].push(getchar());
        }
        getchar();
    }
    stack<char> stk;
    string ans;
    int bu = -1;
    while (cin >> bu && bu != -1) {
        
        if (bu == 0) {
            if (stk.size()) {
                ans.push_back(stk.top());
                stk.pop();
            }
        } else {
            if (stk.size() == s && q[bu].size()) {
                if (stk.size()) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
            }
            if (q[bu].size()) {
                stk.push(q[bu].front());
                q[bu].pop();
            }
        }
    }
    cout << ans << endl;
}