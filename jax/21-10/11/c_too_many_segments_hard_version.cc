#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int ls[N], rs[N];
vector<int> ev[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", ls + i, rs + i);
        ev[ls[i]].push_back(i);
        ev[rs[i] + 1].push_back(-i);
    }

    // 集合中包含了线段的编号，所以不会导致重复移除同一条线段
    // the set also stores the segment's index, so we won't erase twice in the two situation below
    set<pair<int, int>> curSegs;
    vector<int> ans;

    for (int i = 1; i < N; ++i) {
        for (int it : ev[i]) {
            if (it > 0) {
                curSegs.insert({rs[it], it});
            } else {
                // 这里是正常地到达了线段的右端点而移除
                // First situation: we arrived at the position after the segment's right end,
                // so we should remove it to correct our set
                auto iter = curSegs.find({rs[-it], -it});
                if (iter != curSegs.end()) {
                    curSegs.erase(iter);
                }
            }
        }

        while (curSegs.size() > k) {
            // 这里是不满足条件而移除的情况
            // Second situation: we have more than k segments covering current point,
            // so we should remove some rightmost segments to make the set size not greater than k
            ans.push_back(curSegs.rbegin()->second);
            curSegs.erase(prev(curSegs.end()));
        }
    }

    printf("%ld\n", ans.size());
    for (int it : ans) {
        printf("%d ", it);
    }
    puts("\n");
}