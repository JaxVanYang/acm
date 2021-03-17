#include <iostream>
using namespace std;
int n, cnt = 0;
pair<int, int> p[100];
char s[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int i = 0;
    while (i < n) {
        if (s[i] == '?') {
            int a = i;
            while (i < n && s[i] == '?') ++i;
            p[cnt++] = make_pair(a, i - 1);
        } else i++;
    }
    // cout << "ye" << endl;
    for (int i = 0; i < cnt; ++i) {
        int a = p[i].first, b = p[i].second;
        int len  = b - a + 1;
        if (a == 0 || b == n - 1) {
            cout << "Yes" << endl;
            return 0;
        }
        if (s[a - 1] == s[b + 1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}