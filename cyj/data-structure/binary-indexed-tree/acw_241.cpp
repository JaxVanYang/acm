/*
 * @Descripttion: 树状数组求逆序对 
 * @Topic link: https://www.acwing.com/problem/content/243/
 * @Question meaning: 
 * @Status: AC
 * @Author: cyj
 * @Date: 2021-03-17 16:57:14
 * @LastEditTime: 2021-03-17 23:24:36
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

typedef long long LL;

int n, les[N], more[N], a[N], tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for (int i = x; i <= n;  i += lowbit(i)) tr[i] += 1; 
}

LL sum(int x){
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++){
        int y = a[i];
        more[i] = sum(n) - sum(y);
        les[i] = sum(y-1);
        add(y);
    }
    
    memset(tr, 0, sizeof tr);
    LL res1 = 0, res2 = 0;
    for (int i = n; i ; i --){
        int y = a[i];
        res1 += more[i] * (sum(n) - sum(y));
        res2 += les[i] * sum(y-1);
        add(y);
    }
    
    cout << res1 << " " << res2 << endl;
    
    return 0;
}