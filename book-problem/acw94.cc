#include <iostream>
#include <vector>
using namespace std;

int n;
int st; // 居然粗心用 bool 定义 st
vector<int> ans;

void dfs(int cnt) {
    if (cnt > n) {
        for (int &num : ans) printf("%d ", num);
        puts("");
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (st >> i & 1) continue;
        st |= 1 << i;
        ans.push_back(i);
        dfs(cnt + 1);
        ans.pop_back();
        st ^= 1 << i;
    }
}

int main() {
    cin >> n;
    dfs(1);
}