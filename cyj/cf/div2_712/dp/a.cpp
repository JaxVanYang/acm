/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-12 15:07:04
 * @LastEditTime: 2021-08-12 17:15:34
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 5010;

int n;
ll d[N][N], dist[N];
bool st[N];
pair<int, int> p[N];

void prim()
{
    for (int i = 1; i <= n; i ++) dist[i] = 1e18;
    memset(st, 0, sizeof st);

    ll res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i) res = max(res, dist[t]);
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], d[t][j]);
    }

    cout << res << endl;
}


int main(){
    
    int T;
    scanf("%d", &T);
    while (T --){
        for (int i = 1; i <= n; i ++) d[i][i] = 1e18 + 100;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= n; j ++){
                if (i == j) d[i][j] = 0;
                else {
                    int x1 = p[i].x, y1 = p[i].y, x2= p[j].x, y2 = p[j].y;
                    d[i][j] = ((long long)x1-x2) * ((long long)x1-x2) + ((long long)y1-y2) * ((long long)y1-y2);
                }
            }
        }
        prim();
    }
    
    return 0;
}