/*
 * @Descripttion: 超市
 * @Topic link: https://www.acwing.com/problem/content/description/147/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-08 10:31:01
 * @LastEditTime: 2021-04-08 10:31:35
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

int n;
int p[N];

struct node{
    int a, b;
    bool operator< (const node &m) const {
        if (a != m.a){
            return a > m.a;
        }else {
            return b > m.b;
        }
    }
}nodes[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    
    while (cin >> n){
        for (int i = 1; i <= n; i ++) cin >> nodes[i].a >> nodes[i].b;
        for (int i = 1; i < N; i ++) p[i] = i; // 注意初始化到N
        sort(nodes + 1, nodes + n + 1);
        int res = 0;
        for (int i = 1; i <= n; i ++){
            int t = find(nodes[i].b);
            if (t){
                res += nodes[i].a;
                p[t] = t-1;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
