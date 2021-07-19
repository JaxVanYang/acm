/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-19 13:32:38
 * @LastEditTime: 2021-07-19 13:32:39
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

typedef long long ll;
typedef pair<int, int> PII;
#define x first
#define y second

int n, a[N], tr[N], k;
int ans[N], y[N];
bool st[N], st1[N], s[N];
PII p[N];

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for (int i = x; i <= n;  i += lowbit(i)) tr[i] += 1; 
}

void del(int x){
    for (int i = x; i <= n;  i += lowbit(i)) tr[i] -= 1; 
}

ll sum(int x){
    ll res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
//     cin >> n >> k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i ++){
//         cin >> p[i].x >> p[i].y;
        scanf("%d%d", &p[i].x, &p[i].y);
        st[p[i].x] = 1, y[p[i].x] = p[i].y;
    }
    for (int i = 1; i <= n; i ++) add(i);
    int maxv = n;
    for (int i = n; i; i --){
        if (!st[i]) {
            while (1){
                if (!st1[maxv]){
                    ans[i] = maxv;
                    del(maxv);
                    st1[maxv] = 1;
                    maxv --;
                    break;
                }
                else maxv --;
            }
        }
        else {
            int l = 1, r = n;
            while (l < r){
                int mid = l + r >> 1;
                if (sum(mid) >= y[i]) r = mid;
                else l = mid + 1;
            }
            ans[i] = l;
            st1[l] = 1;
            del(l);
        }
    }
    bool flag = 1;
    for (int i = 0; i <= n; i ++) s[i] = 0;
    for (int i = 1; i <= n; i ++) {
        if (s[ans[i]] == 1 || ans[i] == 0) {
            flag = 0;
            break;
        }
        else s[ans[i]] =1;
    }
    if (flag){
//         for (int i = 1; i <= n; i ++) cout << ans[i] << ' ';
        for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
    } else cout << "-1" << endl;
    return 0;
}