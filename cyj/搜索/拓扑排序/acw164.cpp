/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/166/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-21 20:43:28
 * @LastEditTime: 2021-03-22 09:26:15
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 3e4 + 5, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int e[N], ne[N], h[N], idx, in[N];
vector<int> top;
bitset<N> b[N]; 

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topsort(){
    queue<int> q;
    for (int i = 1;  i<= n; i ++){
        if (in[i] == 0) q.push(i);
    }
    while (q.size()){
        int t = q.front();
        top.push_back(t);
        q.pop();

        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (-- in[j] == 0){
                q.push(j);
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        in[b] ++;
    }
    
    topsort();
    
    for (int i = top.size() - 1; i >= 0; i --){
        int x = top[i];
        b[x].reset(), b[x][x] = 1;
        for (int i = h[x]; ~i; i = ne[i]){
            int j = e[i];
            b[x] |= b[j]; 
        }
    }

    for (int i = 1; i <= n; i ++) printf("%d\n", b[i].count());

    return 0;
}
