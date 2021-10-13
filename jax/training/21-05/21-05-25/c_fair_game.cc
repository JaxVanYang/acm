#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++mp[num];
    }
    if (mp.size() != 2) {
        puts("NO");
        return 0;
    }
    int v = -1;
    for (auto &[val, cnt] : mp) {
        if (v == -1) {
            v = cnt;
        } else if (cnt != v) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (auto &[val, _] : mp) {
        printf("%d ", val);
    }
}