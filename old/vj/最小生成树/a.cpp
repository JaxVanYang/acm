/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-09 19:18:12
 * @LastEditTime: 2021-03-09 19:32:13
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;

int g[N][N];
bool st[N];
int dist[N];
int m, n;

int prim(){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    int res = 0;

    for (int i = 0; i < n; i ++){
        int t = -1;
        for (int j = 1; j <= n; j++){
            if (!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }

        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        st[t] = true;

        if (i) res += dist[t];
        for (int j = 1; j <= n; j ++){
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    
    return res;
}

int main(){

    while (cin >> m >> n, m){
        
        for (int i = 0; i < m; i ++){
            int a, b, c;
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = min(g[a][b], c);
        }

        int res = prim();
        if (res == 0x3f3f3f3f) puts("?");
        else cout << res << endl;

    }    


    return 0;
}