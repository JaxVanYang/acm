#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int len = s.length();
    int ans = 0;
    while (i < len) {
        while (i < len && s[i] != 'x') ++i;
        if (i == len) break;
        int cnt = 0;
        while (i < len && s[i] == 'x') ++cnt, ++i;
        if (cnt > 2) ans += cnt - 2;
    }
    cout << ans << endl;
}