/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-10 19:22:56
 * @LastEditTime: 2021-03-10 19:23:44
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5005;

struct node{
    int l, r;
    int sum;
}tr[N * 4];

int n, res;
int w[N];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u, int l, int r){
    if (l > r) return;
    if (l == r){
        tr[u] = {l, r, 0};
    }
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u<<1, l ,mid), build(u<<1|1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if (tr[u].l >= l && tr[u].r <= r){
        return tr[u].sum;
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        int temp;
        if (r <= mid) return query(u<<1, l, r);
        else if (l > mid) return query(u<<1|1, l, r);
        else{
            int s = query(u<<1, l, r) + query(u<<1|1, l, r);
            return s;
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
    
    while (scanf("%d", &n) != EOF){
        res = 0;
        build(1, 1, n);
        // cout << n << endl;
        // for (int i = 0; i <= n * 4; i ++) cout << tr[i].l << " " << tr[i].r << endl;
        // exit(0);
        // cout << "----------\n";
        for (int i = 1; i <= n; i++){
            scanf("%d", &w[i]);
            // cout << i << endl;
            // cout << w[i] << endl;
            w[i] += 1;
            res += query(1, w[i], n);  // 错误点，当w[i]为n时，n + 1越界
            // cout << w[i] << endl;
            
            modify(1, w[i], 1);
            // for (int i = 0; i <= n * 4; i ++) cout << tr[i].l << " " << tr[i].r << " " << tr[i].sum << endl;
            // if (i == 4) exit(0);
        }
        
        int mi = res;
        // cout << res << endl;
        for (int i = 1; i < n; i ++){
            res = res - (w[i] - 1) + n - w[i];
            // cout << res << endl;
            mi = min(res, mi);
        }
        
        printf("%d\n", mi);
    }
    
    return 0;
}