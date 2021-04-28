#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
vector<int> a[maxn];    // a[i] 记录 i 号病毒可变异成的病毒们
bool v[maxn];           // v[i] 表示 i 号病毒是否可以被其他病毒进化而来

vector<int> ans{0};     // 用于维护全局最长链

void update(vector<int> arr) {  // 用当前 bfs 到的链 arr 更新 ans
    if (arr.size() > ans.size()) {  // 长者优先
        ans = arr;
    } else if (arr.size() == ans.size() && arr < ans) { // 相同长度，字典序小者优先，vector 和 string 一样可以直接使用 <
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
            v[a[i][j]] = true;  // 标记可被进化的病毒
        }
    }

    queue<vector<int>> q;   // 记录当前 bfs 到的链
    for (int i = 0; i < n; ++i) {
        // 只记录不可被其他病毒进化而成的病毒
        // 因为如果一个病毒 b 可以被病毒 a 进化而来，那么从 a 开始一定比从 b 开始长
        if (!v[i]) {
            q.push(vector<int>{i});
        }
    }

    while (q.size()) {
        // 每次循环开始的时候，q 里面的链肯定都是相同长度的
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto arr = q.front();
            q.pop();

            int back = arr.back();  // back 也就是当前进化链的最后一个病毒
            if (a[back].size() == 0) {
                continue;
            }

            // 遍历 back 可选择进化的病毒
            for (int u : a[back]) {
                arr.push_back(u);
                q.push(arr);    // 更新 bfs 所用 q
                update(arr);    // 更新答案 ans
                arr.pop_back(); // 还原进化链
            }
        }
    }
    printf("%ld\n", ans.size());
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); ++i) {
        printf(" %d", ans[i]);
    }
}