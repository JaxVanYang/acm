/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/957/F
来源：牛客网
  建立ac自动机后dfs判环
二进制病毒审查委员会最近发现了如下的规律：某些确定的二进制串是病毒的代码。如果某段代码中不存在任何一段病毒代码，那么我们就称这段代码是安全的。现在委员会已经找出了所有的病毒代码段，试问，是否存在一个无限长的安全的二进制代码。
示例：例如如果{011,11,00000 }为病毒代码段，那么一个可能的无限长安全代码就是010101 \cdots010101⋯。如果{01,11,000000 }为病毒代码段，那么就不存在一个无限长的安全代码。
请写一个程序，读入病毒代码，判断是否存在一个无限长的安全代码，将结果输出。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-21 15:40:09
 * @LastEditTime: 2021-07-21 15:40:42
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e4 + 10;

int tr[N][2], idx, q[N], ne[N], cnt[N];
bool vis[N], ins[N];
int n;

void insert(string x, int u){
    int p  = 0;
    for (int i = 0; i < x.size(); i ++){
        int c = x[i] - '0';
        if (!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
    cnt[p] ++;
}

void build(){
    int hh = 0, tt = -1;
    for (int i  = 0; i <2; i++){
        if (tr[0][i]) q[++ tt] = tr[0][i];
    }
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = 0; i <2; i ++){
            int p = tr[t][i];
            if (!p){
                tr[t][i] = tr[ne[t]][i];
            }
            else {
                ne[p] = tr[ne[t]][i];
                cnt[p] += cnt[ne[p]];
                q[ ++ tt] = p;
            }
        }
    }
    
}

bool dfs(int p){
    if (ins[p]) return true;
    if (cnt[p] || vis[p]) return false;
    ins[p] = 1;
    vis[p] = 1;
    for (int i = 0; i < 2; i ++){
        if (tr[p][i] && dfs(tr[p][i])) return true; 
    }
    ins[p] = 0;
    return false;
}

int main(){
    cin >> n;
    for (int i = 1;i <= n; i ++){
        string a;
        cin >> a;
        insert(a,i);
    }
    build();
    if (dfs(0)) cout << "TAK\n";
    else cout << "NIE\n";
    return 0;
}