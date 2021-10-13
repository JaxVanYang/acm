#include <iostream>
using namespace std;

int cnt[26] = {0};

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (char ch : s) {
        cnt[ch - 'a']++;
        if (cnt[ch - 'a'] > k) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}