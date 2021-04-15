/*
 * @Descripttion: 奇偶游戏 带边权的并查集解法
 * @Topic link: https://www.acwing.com/problem/content/241/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-08 11:33:03
 * @LastEditTime: 2021-04-08 11:52:55
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10;
unordered_map<int, int> s; 
int p[N], d[N], cnt;
int n, m;

int find(int x){
    if (p[x] != x){
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    } 
    return p[x];
}

int get(int x){
    if (!s.count(x)) s[x] = ++ cnt;
    return s[x];
}

int main(){
    cin >> n >> m;
    int res = m;
    for (int i = 1; i < N; i ++) p[i] = i;
    for (int i = 1; i <= m; i ++){
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b); // 此处为是s[l - 1] 与 s[r]的关系
        int t = 0;
        if (type == "odd") t = 1;
        int pa = find(a), pb = find(b);
        if (pa == pb){
            if (d[a] ^ d[b] != t){
                res = i - 1;
                break;
            }
        }else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }
    
    cout << res << endl;
    
    return 0;
}



