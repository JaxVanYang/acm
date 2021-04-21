#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    set<char> vowel{'a', 'e', 'i', 'o', 'u'};
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'n' && !vowel.count(s[i])) {
            if (i == n - 1 || !vowel.count(s[i + 1])) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
}