#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int in[maxn], out[maxn];

inline void no() {
    puts("-1");
    exit(0);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    vector<int> ans;
    vector<int> peo;
    int cnt = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            if (in[a[i]]) {
                no();
            }
            in[a[i]] = 1;
            peo.push_back(a[i]);
            ++cnt;
        } else if (a[i] < 0) {
            if (in[-a[i]] == 0 || out[-a[i]]) {
                no();
            }
            out[-a[i]] = 1;
            --cnt;
        }
        ++c;
        if (cnt == 0) {
            ans.push_back(c);
            for (int num : peo) {
                in[num] = out[num] = 0;
            }
            peo.clear();
            c = 0;
        }
    }
    if (cnt != 0) {
        no();
    }
    printf("%ld\n", ans.size());
    for (int c : ans) {
        printf("%d ", c);
    }
}