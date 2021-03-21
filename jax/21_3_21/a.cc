#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 305;
int a[maxn], b[maxn], cpy[maxn];
int cnt;
void merge(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || i <= mid && a[i] <= a[j]) b[k] = a[i++];
        else b[k] = a[j++], cnt += mid - i + 1;
    }
    for (int k = l; k <= r; ++k) a[k] = b[k];
}

void mergeDown(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    mergeDown(l, mid);
    mergeDown(mid + 1, r);
    
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || i <= mid && a[i] >= a[j]) b[k] = a[i++];
        else b[k] = a[j++], cnt += mid - i + 1;
    }
    for (int k = l; k <= r; ++k) a[k] = b[k];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) scanf("%d", cpy + i);
        cnt = 0;
        memcpy(a, cpy, sizeof(cpy));
        // for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        // cout << endl;
        merge(0, n - 1);
        int ans = cnt;
        // cout << "ans = " << ans << endl;
        cnt = 0;
        memcpy(a, cpy, sizeof(cpy));
        // for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        // cout << "cnt = " << cnt << endl;
        mergeDown(0, n - 1);
        ans = min(ans, cnt);
        printf("%d\n", n * ans);
    }
}