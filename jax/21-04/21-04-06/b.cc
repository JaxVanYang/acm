#include <iostream>
using namespace std;

const int maxn = 105;
int a[maxn];

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a[num]++;
        ans = max(ans, a[num]);
    }
    cout << ans << endl;
}