/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-20 23:20:00
 * @LastEditTime: 2021-07-20 23:21:16
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1e7 + 5, M = 1e5 + 10, L = 102;

int tr[M * L][4], ne[M * L], idx, q[M * L];
bool st[M * L];
char s[N], a[M][L];
int n, m;

int get(char c){
    if (c == 'E') return 0;
    else if (c == 'S') return 1;
    else if (c == 'W') return 2;
    else if (c == 'N') return 3;
}

void insert(int x){
    int p = 0;
    for (int i = 0 ; a[x][i]; i ++){
        int t = get(a[x][i]);
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
}

void build(){
    int hh = 0, tt = -1;
    for (int i = 0; i < 4; i ++){
        if (tr[0][i]) q[ ++ tt] = tr[0][i];
    }
    
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = 0; i < 4;i  ++){
            int p = tr[t][i];
            if (!p){
                tr[t][i] = tr[ne[t]][i];
            }
            else {
                ne[p] = tr[ne[t]][i];
                q[++ tt] = p;
            }
        }
    }
}

int dfs(int u){
    int p = 0, depth = 0;
    for (int i = 0; a[u][i]; i ++){
        int t = get(a[u][i]);
        if (st[tr[p][t]]) depth = max(depth, i + 1);
        p = tr[p][t];
    }
    return depth;
}

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 1; i <= m; i ++){
        scanf("%s", a[i]);
//         printf("%s\n", a[i]);
        insert(i);
    }
    build();
    scanf("%s", s);
    for (int i = 0, j = 0; s[i]; i ++){
        int c = get(s[i]);
        j = tr[j][c];
        // j是s[i]能匹配到的最深的位置，由此j一定出现过，到j的字串也一定出现过，所以需要while一遍
        int tmp = j;
        while (tmp){
            st[tmp] = 1;
            tmp = ne[tmp];
        }
    }
    for (int i = 1; i <= m; i ++){
        printf("%d\n", dfs(i));
    }
    return 0;
}