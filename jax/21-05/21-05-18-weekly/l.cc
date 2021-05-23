#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        if (s == t) {
            puts("Equal");
        } else {
            if (s.front() == t.front() && s.back() == t.back()) {
                sort(s.begin() + 1, s.end() - 1);
                sort(t.begin() + 1, t.end() - 1);
            }
            if (s == t) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
}