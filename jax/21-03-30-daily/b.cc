#include <iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < p; ++i) {
        char ch = '.';    // record valid char
        for (int j = i; j < s.length(); j += p) {
            if (ch == '.' && s[j] != '.') {
                ch = s[j];
            } else if (ch != '.' && s[j] != '.' && s[j] != ch) {
                flag = true;
            }
        }
    }
    if (!flag)
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.' && i + p < s.length()) {
            flag = true;
            if (s[i + p] == '.') {
                s[i] = '0';
                s[i + p] = '1';
            } else {
                s[i] = s[i + p] == '0' ? '1' : '0';
            }
            break;
        } else if (s[i] == '.' && i - p >= 0) {
            flag = true;
            if (s[i - p] == '.') {
                s[i] = '0';
                s[i - p] = '1';
            } else {
                s[i] = s[i - p] == '0' ? '1' : '0';
            }
            break;
        }
    }
    if (flag) {
        for (auto &ch : s) if (ch == '.') ch = '0';
        cout << s << endl;
    } else {
        puts("No");
    }
}