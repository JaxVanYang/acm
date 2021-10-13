#include <iostream>
using namespace std;
char nb[26][2];

void init() {
    for (int i = 0; i < 26; ++i) {
        nb[i][0] = (i + 1) % 26 + 'a';
        nb[i][1] = (i + 25) % 26 + 'a';
    }
    // 注意边界情况
    nb[0][1] = 'A';
    nb[25][0] = ' ';
}

bool valid(char a, char b) {
    int pa = a - 'a', pb = b - 'a';
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (nb[pa][i] == nb[pb][j]) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; 2 * i < n; ++i) {
        if (!valid(s[i], s[n - 1 - i])) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    init();
    // for (int i = 0; i < 26; ++i) {
    //     cout << char(i + 'a') << ": ";
    //     for (int j = 0; j < 2; ++j) {
    //         cout << nb[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int t;
    scanf("%d", &t);
    while (t--) {
        solve();    
    }
}