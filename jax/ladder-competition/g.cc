#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
using namespace std;
using ll = long long;
const int maxn = 2e4 + 5;
const int inf = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<int> low, high;
    int minV = inf, maxV = -1;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num == minV) {
            low.push_back(num);
        } else if (num < minV) {
            low.clear();
            low.push_back(num);
            minV = num;
        }
        if (num == maxV) {
            high.push_back(num);
        } else if (num > maxV) {
            high.clear();
            high.push_back(num);
            maxV = num;
        }
    }
    printf("%d %d\n", minV, low.size());
    printf("%d %d\n", maxV, high.size());
}