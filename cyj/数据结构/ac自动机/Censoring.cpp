/*
 * @Descripttion: 
 S字符串中删除m个关键词，删除关键字后空缺部分左右合并可能产生新的关键字
   S删掉关键字后与前面的字符串不再有关系，维护两个栈，分别是未删除的s字符串以及j在各点匹配到的位置
 * @Topic link: https://ac.nowcoder.com/acm/contest/957/C
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-21 00:14:13
 * @LastEditTime: 2021-07-22 22:57:43
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int stk2[N], top;
char stk[N];
int tr[N][26], ne[N], idx, q[N], cnt[N];
bool st[N];
char s[N], a[N];

void insert(){
    int p = 0;
    for (int i = 0; a[i]; i ++){
        int c = a[i] - 'a';
        if (!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
    cnt[p] = strlen(a);
}

void build(){
    int hh = 0, tt = -1;
    for (int i = 0; i < 26;i ++){
        if (tr[0][i]) q[++ tt] = tr[0][i];
    }
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = 0; i < 26; i ++){
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[ne[t]][i];
            else {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}

int main(){
    scanf("%s", s);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        scanf("%s", a);
        insert();
    }
    build();
    
    for (int i = 0, j = 0; s[i]; i ++){
        int c = s[i] - 'a';
        j = tr[j][c];
        stk[++ top] = s[i];
        stk2[top] = j;
        if (cnt[j]){
            top -= cnt[j];
            if (!top) j = 0;
            else j = stk2[top];
        }
    }
    for (int i = 1; i <= top; i ++) cout << stk[i];
    return 0;
}