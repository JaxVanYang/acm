/*
 * @Descripttion: 
 * @Topic link: https://www.luogu.com.cn/problem/P4735
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-19 21:34:59
 * @LastEditTime: 2021-08-19 21:35:18
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N  = 6e5 + 10, M = N  * 2 + N * 25;
int n, m;
int tr[M][2], root[N], idx, w[N];
int max_id[M], s[N];

void insert(int k, int p, int q){
    max_id[q] = k;
    for (int i = 24; i >= 0; i --){
        int v = s[k] >> i & 1;
        if (p) tr[q][v^1] = tr[p][v^1];
        tr[q][v] =  ++ idx;
        max_id[idx] = k;
        p = tr[p][v], q = tr[q][v];
    }
}

int query(int q, int l, int x){
    for (int i = 24; i >= 0; i --){
        int v = x >> i & 1;
        if (max_id[tr[q][v^1]] >= l) q = tr[q][v^1];
        else q = tr[q][v];
    }
    return x ^ s[max_id[q]];
}

int main(){
    scanf("%d%d", &n, &m);
    max_id[0] = -1;
    root[0] = ++ idx;
    insert(0, 0, root[0]);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &w[i]); 
        root[i] = ++ idx;
        s[i] = s[i-1] ^ w[i];
        insert(i, root[i-1], root[i]);
    }
    while (m --){
        char op[3];
        int l, r, x;
        scanf("%s", op);
        if (*op == 'A'){
            scanf("%d", &x);
            n ++;
            root[n] = ++ idx;
            s[n] = s[n-1] ^ x;
            insert(n, root[n-1], root[n]);
        }
        else {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r-1], l-1, x ^ s[n]));
        }
    }
    return 0;
}