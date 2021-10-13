#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int maxn = 2e6 + 5;
// int a[maxn];
// char s[maxn * 2];

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int> small, big;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        // scanf("%d", a + i);
        int num;
        scanf("%d", &num);
        mp[num] = i;
        small.push(-num);
    }
    getchar();
    for (int i = 0; i < 2 * n; ++i) {
        char ch = getchar();
        if (ch == '0') {
            int num = -small.top();
            small.pop();
            big.push(num);
            printf("%d ", mp[num]);
        } else {
            int num = big.top();
            big.pop();
            printf("%d ", mp[num]);
        }
    }
}