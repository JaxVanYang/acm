#include <iostream>
#include <algorithm>
using namespace std;
int cnts[4];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n < 4) {
        cout << "NO" << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    int cnt = 0;
    int i = 0;
    while (i < n) {
        int t = i;
        while (t < n && s[t] == s[i]) {
            cnts[cnt]++;
            t++;
        }
        i = t;
        ++cnt;
        if (cnt > 4) {
            cout << "NO" << endl;
            return 0;
        }
    }

    bool flag = true;
    if (cnt == 1) {
        flag = false;
    } else if (cnt == 2) {
        for (int i =  0; i < 2; ++i) if (cnts[i] == 1) flag = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}