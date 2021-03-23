/*
 * @Descripttion: 树状数组维护差分序列
 * @Topic link: https://www.acwing.com/problem/content/248/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 23:24:46
 * @LastEditTime: 2021-03-18 21:26:16
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;

int n ,m;
typedef long long LL;
int a[N];
LL tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int v){
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

LL sum(int x){
    LL res = 0;
    for (int i = x; i ; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        add(i, a[i] - a[i-1]);
    }
    int l ,r, d;
    char op[3];
    for (int i = 0;  i< m; i ++){
        scanf("%s", op);
        if (*op == 'C'){
            scanf("%d%d%d", &l, &r, &d);
            add(l, d);
            add(r + 1, -d);
        }else {
            scanf("%d", &d);
            cout << sum(d) << endl;
        }
    }
    
    return 0;
}