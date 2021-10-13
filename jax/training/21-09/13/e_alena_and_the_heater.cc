#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
string b;

int calc(int i) {
    int cnt[2] = {0, 0};
    for (int j = i - 4; j < i; ++j) {
        cnt[b[j] - '0']++;
    }

    if (cnt[0] == 4) {
        return 0;
    }
    if (cnt[1] == 4) {
        return 1;
    }

    return 2;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> b;

    int l = -1e9 - 1, r = 1e9 + 1;

    for (int i = 4; i < n; ++i) {
        int code = calc(i);

        if (code == 1 && b[i] == '0') {
            r = min(r, *min_element(a + i - 4, a + i + 1));
        } else if (code == 0 && b[i] == '1') {
            l = max(l, *max_element(a + i - 4, a + i + 1));
        }
    }

    cout << l + 1 << " " << r - 1 << endl;
}