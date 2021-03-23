/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-10 15:10:49
 * @LastEditTime: 2021-03-10 15:11:16
 */

// 模板题 求和

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e4 + 5;

struct node{
    int l, r;
    int sum;
}tr[N * 4];

int w[N];
int T, n;

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l == r){
        tr[u] = {l, l, w[l]};
    }else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u<<1, l, mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        int sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) sum += query(u<<1, l, r);
        else if (l > mid) sum += query(u<<1|1, l, r);
        else {
            int left = query(u<<1, l, r), right = query(u<<1|1, l, r);
            sum += left + right;
            return sum;
        }
    }
}

void modify(int u, int x, int v){
    if (tr[u].l == x && tr[u].r == x){
        tr[u].sum += v;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u<<1, x, v);
        else modify(u<<1|1, x, v);
        
        pushup(u);
    }
}

int main(){
    scanf("%d", &T);
    int p = 1;
    while (T --){
        printf("Case %d:\n", p ++);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++){
            scanf("%d", &w[i]);
        }
        build(1, 1, n);
        string op;
        // exit(0);
        while (cin >> op, op != "End"){
            int i, j;
            scanf("%d%d", &i, &j);
            if (op == "Add"){
                modify(1, i, j);
            }
            else if (op == "Sub"){
                modify(1, i, -j);
            }
            else{
                int s = query(1, i, j);
                printf("%d\n", s);
            }
        }
    }
    
    
    return 0;
}