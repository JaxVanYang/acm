#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
// #include <set>
using namespace std;
using ll = long long;
const int maxn = 2005;
int a[maxn], b[maxn];
int mp[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memcpy(b, a, sizeof(a));
    sort(b, b + n);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += b[n - 1 - i];
        mp[b[n - 1 - i]]++;
    }
    vector<int> arr{-1};
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]]) {
            arr.push_back(i);
            mp[a[i]]--;
        }
    }
    arr.pop_back();
    arr.push_back(n - 1);
    cout << ans << endl;
    for (int i = 1; i <= k; ++i) {
        cout << arr[i] - arr[i - 1] << ' ';
    }
}