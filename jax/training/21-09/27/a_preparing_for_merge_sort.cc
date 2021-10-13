#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> ans;

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);

        int l = 0, r = ans.size();

        while (l < r) {
            int mid = l + r >> 1;

            if (ans[mid].back() < num) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l < ans.size()) {
            ans[l].push_back(num);
        } else {
            ans.push_back({num});
        }
    }

    for (auto &row : ans) {
        for (int val : row) {
            printf("%d ", val);
        }
        puts("");
    }
}