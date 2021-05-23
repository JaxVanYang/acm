#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;
const ll mod = 1e15 + 7;

int main() {
    string s, begin, end;
    cin >> s >> begin >> end;
    size_t n = s.length(), len1 = begin.length(), len2 = end.length();
    vector<int> pre, post;
    size_t last = 0;
    while (last < n) {
        size_t p = s.find(begin, last);
        if (p >= n) break;
        pre.push_back(p);
        last = p + 1;
    }
    last = 0;
    while (last < n) {
        size_t p = s.find(end, last);
        if (p >= n) break;
        post.push_back(p);
        last = p + 1;
    }
    int ans = 0;
    // Note: the range of hashing should be long long
    unordered_set<ll> st;
    for (int l : pre) {
        ll tmp = 0, i = l;
        for (int r : post) {
            if (r < l || l + len1 > r + len2) continue;
            // s[r, r + len2) are all equal, so no need to include
            // string tmp = s.substr(l, r - l);
            while (i < r) {
                tmp = ((ll)tmp * 31 + s[i++]) % mod;
            }
            if (!st.count(tmp)) {
                ++ans;
                st.insert(tmp);
            }
        }
    }
    printf("%d\n", ans);
}