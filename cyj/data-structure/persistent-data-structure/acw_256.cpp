/*
 * @Descripttion: 可持久化trie
 * @Topic link: https://www.acwing.com/problem/content/258/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-19 14:55:45
 * @LastEditTime: 2021-03-28 12:12:39
 */

// 注意想清楚特判的处理

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 6e5 + 5, M = N * 25;

int tr[M][2];
int n, m;
int max_id[M], s[N], root[N], idx;

void insert(int i, int k, int p, int q){
    if (k < 0){
        max_id[q] = i;
        return;
    }
    int v = s[i] >> k & 1;
    if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
    tr[q][v] = ++ idx;
    insert(i, k - 1, tr[p][v], tr[q][v]);
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
}

int query(int root, int val, int l){
    int q = root;
    for (int i = 23; i >= 0; i --){
        int t = val >> i & 1;
        if (max_id[tr[q][t ^ 1]] >= l && tr[q][t ^ 1]) q = tr[q][t ^ 1];
        else q = tr[q][t];
    }
    
    return val ^ s[max_id[q]];
}

int main(){
    
    scanf("%d%d", &n, &m);
    // root[0] = ++ idx;
    // max_id[0] = -2;
    // insert(0, 23, 0, root[0]);
    // cout << max_id[0] << endl;
    for (int i =1 ; i<= n;  i++){
        int t;
        scanf("%d", &t);
        s[i] = s[i-1] ^ t;
        root[i] = ++ idx;
        insert(i, 23, root[i-1], root[i]);
    }
    
    char op[3];
    int l, r, x;
    
    while (m --){
        scanf("%s", op);
        if (*op == 'A'){
            scanf("%d", &x);
            n ++;
            s[n] = s[n-1] ^ x;
            root[n] = ++ idx;
            insert(n, 23, root[n-1], root[n]);
        }else {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r-1], s[n] ^ x, l - 1));
        }
    }
    // for (int i = 0; i < 500500; i ++) cout << tr[i][0] << " ";
    // cout << endl;
    // for (int i = 0; i < 10000; i ++) cout << tr[i][1] << " ";
    // cout << endl;
    
    return 0;
}