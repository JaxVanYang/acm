/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 08:42:16
 * @LastEditTime: 2021-04-28 09:34:26
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
typedef long long LL;
struct node{
    int a, b, c;
    bool used;
    bool operator< (const node &m) const {
        return c > m.c;
    }
}edge[N];
int n, m, k;
int p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    sort(edge, edge + m);
    LL res = 0;
    int minw = 1e9 + 7;
    for (int i = 1 ; i <= n; i ++) p[i] = i;
    for (int i = 0; i < m; i ++){
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        int pa = find(a), pb = find(b);
        
        if (pa != pb){
            edge[i].used = 1;
            if (c < k) res += k - c;
            else minw = min(minw, c);
            p[pa] = pb;
        }        
    }
    if (!res) cout << minw - k;
    else cout << res << endl;

    return 0;
}