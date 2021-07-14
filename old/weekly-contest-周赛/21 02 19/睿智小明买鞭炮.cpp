/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-19 19:22:54
 * @LastEditTime: 2021-02-25 09:12:06
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;

vector<PII> w;
int n, m;
LL f[N], a[N]; 

int find(int x){
    int l = 0, r = n;
    while (l < r){
        int mid = l + r >> 1;
        if (w[mid].first > x) r = mid;
        else l = mid + 1;
    }
    
    return r;
}

int main(){
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        w.push_back({a, b});
        f[i] = (LL)a * b;
    }
    
    LL e = 1e19;
    for (int i = n - 1; i >= 0 ; i--){
        e = min(e, f[i]);
        a[i] = e;
    }
    
    LL res, t;
    for (int j = 0; j < m; j ++){
        cin >> t;
        res = 1e18;
        int pos = find(t);
        if (pos != n) res = (LL)w[pos - 1].second * t;
        else {
            cout << (LL)w[n - 1].second * t << endl;
            continue;
        }
        
        res = min(res, a[pos]);
        
        cout << res << endl;
    }
    
    return 0;
}