#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const char el = '\n';
bool st[N];
int a[N], b[N];

ll count(int a[], int b[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ll ret = count(a, b, l, mid) + count(a, b, mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i++];
        else ret += mid - i + 1, b[k] = a[j++];
    }
    for (int k = l; k <= r; ++k) a[k] = b[k];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // cout << "a[" << i << "] = " << a[i] << el;
        if (st[a[i] + 1]) ++a[i];
        else st[a[i]] = true;
        // cout << "a[" << i << "] = " << a[i] << el;
    }
    cout << count(a, b, 0, n - 1) << el;
}