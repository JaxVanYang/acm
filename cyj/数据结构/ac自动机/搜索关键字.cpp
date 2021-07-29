/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/957/A
来源：牛客网

给定n个长度不超过50的由小写英文字母组成的单词准备查询，以及一篇长为m的文章，
问：文中出现了多少个待查询的单词。多组数据。
 * @Topic link: https://ac.nowcoder.com/acm/contest/957/A
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-20 17:52:55
 * @LastEditTime: 2021-07-22 22:59:25
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e4 + 5, M = 50, L = 1e6 + 10;

int n, m;
char s[L];
int tr[N * M][26], idx, ne[N * M], cnt[N * M], q[N * M];

void insert(string a){
    int p = 0;
    for (int i = 0; i < a.size(); i ++){
        int c = a[i] - 'a';
        if (!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
    cnt[p] += 1;
}

void build(){
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i ++){
        if (tr[0][i]) q[++ tt] = tr[0][i];
    }
    
    while (hh <= tt){
        int t = q[hh ++];
        for (int i = 0; i < 26; i ++){
            int c = tr[t][i];
            if (!c) continue;
            int j = ne[t];
            while (j && (!tr[j][i])) j = ne[j];
            if (tr[j][i]) j = tr[j][i];
            ne[c] = j;
            q[++ tt] = c;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while (T --){
        int res = 0;
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;
        cin >> n;
        while (n --){
            string a;
            cin >> a;
            insert(a);
        }
        build();
        scanf("%s", s);
        for (int i = 0, j = 0; s[i]; i ++){
            int t = s[i] - 'a';
            j = tr[j][t]; // j是s[i]能匹配到的最深的位置，由此j一定出现过，到j的字串也一定出现过，所以需要while一遍
            
            int p = j;
            while (p){
                res += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }
        printf("%d\n", res);
    }
    
    return 0;
}