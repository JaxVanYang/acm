#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> vowel{'a', 'e', 'i', 'o', 'u'};
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'n') continue;
        if (!vowel.count(s[i]) && (i == n - 1 || !vowel.count(s[i + 1]))) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}