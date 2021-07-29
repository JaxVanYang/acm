/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/963/B
来源：牛客网
找无向图的点双连通分量
煤矿工地可以看成是由隧道连接挖煤点组成的无向图。为安全起见，希望在工地发生事故时所有挖煤点的工人都能有一条出路逃到救援出口处。于是矿主决定在某些挖煤点设立救援出口，使得无论哪一个挖煤点坍塌之后，其他挖煤点的工人都有一条道路通向救援出口。
请写一个程序，用来计算至少需要设置几个救援出口，以及不同最少救援出口的设置方案总数。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-19 21:18:48
 * @LastEditTime: 2021-07-19 21:20:00
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1010, M = 510;
typedef unsigned long long ll;
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
int h[N], e[M], ne[M], idx;
int vcc_cnt, root;
bool cut[N];
vector<int> vcc[N];

void add(int a, int b){
    e[idx]=  b, ne[idx]= h[a], h[a] = idx ++;
}

void tarjan(int u){
    dfn[u] = low[u] =  ++ timestamp;
    stk[++ top] = u;
    int cnt = 0;
    if (u == root && h[u] == -1){
        vcc_cnt ++;
        vcc[vcc_cnt].push_back(u);
        return;
    }
    for (int i = h[u]; ~i; i =ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u]){
                cnt ++;
                if (u != root || cnt > 1) cut[u] = 1;
                ++ vcc_cnt;
                int y;
                do {
                    y = stk[top --];
                    vcc[vcc_cnt].push_back(y);
                } while (y != j);
                vcc[vcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
}

int main(){
    int T = 1;
    while (cin >> m, m){
        n = 0;
        memset(h, -1, sizeof h);
        memset(cut, 0 ,sizeof cut);
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(stk, 0, sizeof stk);
        for (int i = 1; i <= vcc_cnt; i ++) vcc[i].clear();
        idx = top = timestamp = vcc_cnt = 0;
        for (int i = 0; i < m; i ++){
            int a, b;
            cin >> a >> b;
            n = max(n, a), n = max(n, b);
            add(a, b), add(b, a);
        }
        for (root = 1; root <= n; root ++){
            if (!dfn[root]) tarjan(root);
        }
        int res = 0;
        ll num = 1;
        for (int i = 1; i <= vcc_cnt; i ++){
            int cnt = 0;
            for (int j = 0; j < vcc[i].size(); j ++){
                if (cut[vcc[i][j]]) cnt ++;
            }
            int s = vcc[i].size();
            if (cnt == 0) res += 2, num *= s * (s-1)  / 2;
            else if (cnt == 1) res ++, num *= s-1;
        }
        
        printf("Case %d: %d %llu\n", T ++, res, num);
    }
    
    return 0;
}