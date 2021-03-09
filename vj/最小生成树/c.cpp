/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-09 21:01:05
 * @LastEditTime: 2021-03-09 21:57:57
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 105, M = N * N / 2;

struct edge{
    int a, b, c, type;
    edge(){}
    edge(int a, int b, int c, int d):a(a), b(b), c(c), type(d){}
    bool operator< (const edge &m){
        return c < m.c;
    }
}edges[M];

int p[N];
int n;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    // int T = 1;
    ios::sync_with_stdio(false);
    while (cin >> n, n){
        // cout << "n " << n << endl;
        // cout << T ++ << endl;
        int m = n * (n-1) / 2;
        // cout << "bbb " << m << endl;
        for (int i = 1; i <= n; i ++) p[i] = i;
        for (int i = 1; i <= m; i ++){
            // cout << "i " << i << endl;
            // cout << "m " << m << endl; 
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            edges[i] = edge(a, b, c, d);
            if (d){
                int pa = find(a), pb = find(b);
                p[pa] = pb;
            }
        }

        sort(edges + 1, edges + m + 1);
        
        int res = 0;
        for (int i = 1; i <= m; i ++){
            if (!edges[i].type){
                int a = edges[i].a, b = edges[i].b, c= edges[i].c;
                int pa = find(a), pb = find(b);
                if (pa != pb){
                    p[pa] = pb; 
                    res += c;
                }
            }
        }
    
        cout << res << endl;
    }
    

    return 0;
}