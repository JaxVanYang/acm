/*
 * @Descripttion: 奇偶游戏 并查集扩展域解法（枚举思想）
 *  若集合中一个条件成立，则该集合中所有条件均成立
 * @Topic link: https://www.acwing.com/problem/content/241/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-08 12:23:30
 * @LastEditTime: 2021-04-08 12:25:34
 */


#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 2e4 + 10, of = N / 2;
unordered_map<int, int> s; 
int p[N], cnt;
int n, m;

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
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
        a = get(a - 1), b = get(b);
        
        if (type == "odd"){
            if (find(a) == find(b)){
                res = i - 1;
                break;
            }
            p[find(a)] = find(b + of);
            p[find(b)] = find(a + of);
         }
         else {
             if (find(a) == find(b + of)){
                 res = i - 1;
                 break;
             }
             p[find(a)] = find(b);
             p[find(a + of)] = find(b + of);
         }
    }
    cout << res << endl;
    
    return 0;
}



