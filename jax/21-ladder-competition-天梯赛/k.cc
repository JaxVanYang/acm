#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
// #include <unordered_map>
#include <map>
#include <deque>
using namespace std;
using ll = long long;
const int maxn = 1e4 + 5;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<vector<int>, int> mp;
    for (int i = 0; i < n; ++i) {
        vector<int> arr(m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[j]);
        }
        mp[arr]++;
    }
    vector<pair<int, vector<int>>> arr;
    for (auto p : mp) {
        arr.push_back(make_pair(p.second, p.first));
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a.first > b.first || a.first == b.first && a.second < b.second;
    });
    printf("%ld\n", arr.size());
    for (auto p : arr) {
        printf("%ld ", p.first);
        if (p.second.size()) {
            printf("%d", p.second[0]);
        }
        for (int i = 1; i < p.second.size(); ++i) {
            printf(" %d", p.second[i]);
        }
        puts("");
    }
}