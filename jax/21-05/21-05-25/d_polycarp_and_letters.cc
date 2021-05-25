#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    auto count = [&](int l, int r) {
        map<int, int> mp;
        for (int i = l; i < r; ++i) {
            mp[s[i]]++;
        }
        return mp.size();
    };
    int l = 0;
    while (l < n) {
        while (l < n && isupper(s[l])) ++l;
        int r = l;
        while (r < n && islower(s[r])) ++r;
        ans = max(ans, (int)count(l, r));
        l = r;
    }
    cout << ans << endl;
}