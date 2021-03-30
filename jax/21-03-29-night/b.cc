#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<string, string> mp{{"purple", "Power"}, {"green", "Time"}, {"blue", "Space"}, {"orange", "Soul"}, {"red", "Reality"}, {"yellow", "Mind"}};
    set<string> ans;
    // for (auto &p : mp) cout << p.first << ": " << p.second << endl;
    for (auto &p : mp) ans.insert(p.second);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ans.erase(mp[s]);
    }
    cout << ans.size() << endl;
    for (auto &each : ans) cout << each << endl;
}