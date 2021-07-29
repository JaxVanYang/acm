/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning:
 * 链接：https://ac.nowcoder.com/acm/contest/957/D
来源：牛客网

某人读论文，一篇论文是由许多单词组成。但他发现一个单词会在论文中出现很多次，现在想知道每个单词分别在论文中出现多少次。 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-20 21:09:42
 * @LastEditTime: 2021-07-20 21:10:02
 */

 #include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int tr[N][26], idx, f[N], id[210], q[N], ne[N];
int n;

void insert(string x, int u){
    int p  = 0;
    for (int i = 0; i < x.size(); i ++){
        int c = x[i] - 'a';
        if (!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
        f[p] ++;
    }
    id[u] = p;
}

void build(){
    int hh = 0, tt = -1;
    for (int i  = 0; i <26; i++){
        if (tr[0][i]) q[++ tt] = tr[0][i];
    }
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = 0; i <26; i ++){
            int p = tr[t][i];
            if (!p){
                tr[t][i] = tr[ne[t]][i];
            }
            else {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
    
}

int main(){
    cin >> n;
    for (int i = 1;i <= n; i ++){
        string a;
        cin >> a;
        insert(a,i);
    }
    build();
    // 宽搜的倒序即为拓扑序
    for (int i = idx-1; i >= 0; i --)  f[ne[q[i]]] += f[q[i]];
    for (int i = 1; i <= n; i ++) cout << f[id[i]] << endl;
    return 0;
}