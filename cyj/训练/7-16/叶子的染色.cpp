/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/19914
来源：牛客网

给一棵m个结点的无根树，你可以选择一个度数大于1的结点作为根，然后给一些结点（根、内部结点和叶子均可）着以黑色或白色。你的着色方案应该保证根结点到每个叶子的简单路径上都至少包含一个有色结点（哪怕是这个叶子本身）。 
对于每个叶结点u，定义c[u]为从根结点从U的简单路径上最后一个有色结点的颜色。给出每个c[u]的值，设计着色方案，使得着色结点的个数尽量少。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-16 14:15:16
 * @LastEditTime: 2021-07-16 14:15:33
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, INF = 1e9;
int h[N], e[N * 2], ne[N * 2], idx;
int c[N], n, m;
int f[N][4];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u,int fa){
    if (u <= m){
        f[u][1] = c[u] == 1 ? 1 : INF;
        f[u][0] = !c[u] ? 1 : INF;
        f[u][2] = INF;
    }else {
        f[u][0] = f[u][1] = 1;
    }
    
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        f[u][0] += min(f[j][0] - 1, min(f[j][1], f[j][2]));
        f[u][1] += min(f[j][1] - 1, min(f[j][0], f[j][2]));
        f[u][2] += min(f[j][0], min(f[j][1], f[j][2]));
    }
}

void dfs2(int u, int fa){
    if (u > m){
        for (int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            if (j == fa) continue;
            int t0 = f[u][0] - min(f[j][0]-1, min(f[j][1], f[j][2]));
            int t1 = f[u][1] - min(f[j][1]-1, min(f[j][0], f[j][2]));
            int t2 = f[u][2] - min(f[j][0], min(f[j][1], f[j][2]));
            f[j][0] += min(t0 - 1, min(t1, t2));
            f[j][1] += min(t1 - 1, min(t0, t2));
            f[j][2] += min(t1, min(t2, t0));
            dfs2(j, u);
        }
    }
}

int main(){
    cin >> n>> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i ++) cin >> c[i];
    
    for (int i = 1; i < n; i ++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(m+1, -1);
    dfs2(m + 1, -1);
    int res  =INF;
    for (int i = m + 1; i <= n; i ++) res = min(f[i][0], min(f[i][1], f[i][2]));
    cout << res << endl;
    return 0;
}