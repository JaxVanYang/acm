/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-06 15:54:59
 * @LastEditTime: 2021-03-06 15:54:59
 */

#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, m, q;
int p[N],  s[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    
    cin >> n  >> m >> q;
    for (int i = 1; i<= n;  i++) p[i] = i, s[i] = 1;
    while (m --){
        int a, b;
        cin >> a >> b;
        int pa = find(a),  pb = find(b);
        if (pa != pb){
            p[pa] = pb;
            s[pb] += s[pa];
        }
    }
    
    while (q --){
        int x;
        cin >> x;
        int px = find(x);
        cout << n - s[px] << endl;
    }
    
    return 0;
}