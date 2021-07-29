/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/13249
来源：牛客网

一棵n个点的有根树，1号点为根，相邻的两个节点之间的距离为1。树上每个节点i对应一个值k[i]。
每个点都有一个颜色，初始的时候所有点都是白色的。
你需要通过一系列操作使得最终每个点变成黑色。每次操作需要选择一个节点i，i必须是白色的，
然后i到根的链上（包括节点i与根）所有与节点i距离小于k[i]的点都会变黑，
已经是黑的点保持为黑。问最少使用几次操作能把整棵树变黑。
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-15 22:00:20
 * @LastEditTime: 2021-07-16 14:20:04
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int  w[N];
int h[N], e[M], ne[M], idx;
int n, ans, f[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa){
    for (int i = h[u]; ~i; i =ne[i]){
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        w[u] = max(w[u], w[j] - 1);
        f[u] = max(f[u], f[j] - 1);
    }
    if (!f[u]){
        ans ++;
        f[u] = w[u];
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; i ++){
        int a;
        cin >> a;
        add(a, i), add(i,a);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}