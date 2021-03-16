/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-25 20:32:07
 * @LastEditTime: 2021-02-25 20:32:08
 */

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
#include <limits.h>

typedef long long LL;
using namespace std;

const int N = 200010, M = 2 * N;

int e[M], ne[M], w[M], h[N], hr[N], idx;

int dist[N], distr[N];
bool st[N];
LL res;
int n, m;

LL spfa()
{
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;
    LL ans = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    for (int i = 2; i <= n; i ++){
        if (dist[i] == INT_MAX) return -1;
        else ans += dist[i];
    }
    
    return ans;
}

LL spfar()
{
    
    memset(st, 0, sizeof st);
    distr[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;
    LL ans = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = hr[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (distr[j] > distr[t] + w[i])
            {
                distr[j] = distr[t] + w[i];
                if (!st[j])     
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    for (int i = 2; i <= n; i ++){
        if (distr[i] == INT_MAX) return -1;
        else ans += distr[i];
    }
    
    return ans;
}



void add(int a, int b, int c, int type){
    if (!type){
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
    }
    else {
        e[idx] = b, ne[idx] = hr[a], w[idx] = c, hr[a] = idx ++;
    }
}


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        dist[i] = INT_MAX, distr[i] = INT_MAX;
    }
    memset(h, -1, sizeof h);
    memset(hr, -1, sizeof hr);
    for (int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c, 0);
        add(b, a, c, 1);
    }
    
    LL ans1 = spfa();
    LL ans2 = spfar();
    res = ans1 + ans2;
    if (ans1 != -1 && ans2 != -1) cout << res;
    else cout << -1;
    
    return 0;
}