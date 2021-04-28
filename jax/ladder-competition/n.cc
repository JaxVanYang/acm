#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
// int a[maxn];
vector<int> a(maxn);
vector<int> bs[105];
int id[105];

string toS(vector<int> &arr) {
    string ret;
    for (int num : arr) {
        ret += to_string(num);
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    string s = toS(a);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        bs[i] = vector<int>(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &bs[j]);
        }
        string p = toS(bs[i]);
        id[i] = s.find(p);
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < m; ++i) {
        ans.push_back(make_pair(id[i], i + 1));
    }
    sort(id, id + m);
    if (m > 0) {
        printf("%d", ans[0].second);
    }
    for (int i = 1; i < m; ++i) {
        printf(" %d", ans[i].second);
    }
    puts("");
}