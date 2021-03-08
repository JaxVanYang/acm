#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> isGood(26, false);
    int ans = 26;
    int n = str.length(), i = 0;
    while (i < n) {
        int cnt = 1;
        while (i + 1 < n && str[i] == str[i + 1]) {
            ++i;
            ++cnt;
        }
        if (cnt & 1) {
            if (!isGood[str[i] - 'a']) {
                --ans;
                isGood[str[i] - 'a'] = true;
            }
        }
        ++i;
    }
    cout << ans << endl;
}