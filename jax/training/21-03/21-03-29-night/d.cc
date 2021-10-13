#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 105;
int a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    vector<int> ans;
    set<int> st;
    for (int i = 0;  i < n; ++i) {
        if (!st.count(a[i])) {
            st.insert(a[i]);
            ans.push_back(i + 1);
        }
    }
    if (ans.size() < k) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
    }
}