#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 5;
vector<int> a[maxn];
bool v[maxn];

vector<int> ans{0};

void update(vector<int> arr) {
    if (arr.size() > ans.size()) {
        ans = arr;
    } else if (arr.size() == ans.size() && arr < ans) {
        ans = arr;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        a[i] = vector<int>(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i][j]);
            v[a[i][j]] = true;
        }
    }

    queue<vector<int>> q;
    for (int i = 0; i < n; ++i) {
        if (!v[i]) {
            q.push(vector<int>{i});
        }
    }
    while (q.size()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto arr = q.front();
            q.pop();
            int back = arr.back();
            if (a[back].size() == 0) {
                continue;
            }
            for (int u : a[back]) {
                arr.push_back(u);
                q.push(arr);
                update(arr);
                arr.pop_back();
            }
        }
    }
    printf("%ld\n", ans.size());
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); ++i) {
        printf(" %d", ans[i]);
    }
}