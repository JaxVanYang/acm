/*
 * @Descripttion: 前缀和题
 * @Topic link: http://codeforces.com/contest/1015/problem/E2
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-09-09 19:53:55
 * @LastEditTime: 2021-09-09 21:45:30
 */

 #include <cstdio>
 #include <iostream>
 #include <cstring>

 using namespace std;

 const int N = 1010;
 
 struct node {
     int l, r, u, d;
 }a[N][N];
int g[N][N];
int st[N][N];
int n, m;
 int main(){
     scanf("%d%d", &n, &m);
     int tot = 0;
     for (int i = 1; i <= n; i ++){
         char c[1010];
         scanf("%s",c + 1);
         for (int j = 1; j <= m; j ++){
             if (c[j] == '*') g[i][j] = 1, tot ++;
             else g[i][j] = 0;
         }
    }
    // 递推求出其l，r，d，u的最长长度
    for (int i = 1; i <= n; i ++){ 
        for (int j = 1; j <= m; j ++){
            if (!g[i][j]) continue;
            if (i-1 && g[i-1][j]) a[i][j].u = a[i-1][j].u+1;
            if (j-1 && g[i][j-1]) a[i][j].l = a[i][j-1].l + 1;
        }
    }
    for (int i = n; i >= 1; i --){
        for (int j = m; j; j --){
            if (!g[i][j]) continue;
            if (i+1 <= n && g[i+1][j]) a[i][j].d = a[i+1][j].d + 1;
            if (j + 1 <= m && g[i][j+1]) a[i][j].r = a[i][j+1].r + 1;
        }
    }
    // 二维差分修改
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            int x = min(a[i][j].u, a[i][j].d);
            int y = min(a[i][j].l, a[i][j].r);
            int v = min(x, y);
            a[i][j].u = a[i][j].d = a[i][j].l = a[i][j].r = v;
            if (v){
                st[i][j-v] ++, st[i+1][j-v] --, st[i][j] --, st[i+1][j] ++;
                st[i][j+1] ++, st[i][j+1+v] --, st[i+1][j+1] --, st[i+1][j+1+v] ++;
                st[i-v][j] ++, st[i-v][j+1] --, st[i][j] --, st[i][j+1] ++;
                st[i+1][j] ++, st[i+1+v][j] --, st[i+1][j + 1] --, st[i+1+v][j+1] ++;
                st[i][j] ++, st[i+1][j]--, st[i][j + 1] --, st[i + 1][j + 1] ++;
            } 
        }
    }
    // 前缀和求出各点是否被覆盖
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            st[i][j] += st[i-1][j] + st[i][j-1] - st[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (st[i][j]) tot --;
        }
    }
    if (tot) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (a[i][j].l) tot ++;
        }
    }
    cout << tot << endl;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (a[i][j].l) printf("%d %d %d\n", i, j, a[i][j].l);
        }
    }
     return 0;
 }

 