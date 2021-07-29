/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/957/E
来源：牛客网

给定n个字符串s1, s2, s.., sn
 ，要求找到一个最短的字符串T，使得这n个字符串都是T的子串。
 * @Topic link: https://ac.nowcoder.com/acm/contest/957/E
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-23 09:43:14
 * @LastEditTime: 2021-07-23 09:43:46
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N = 13 * 50, M = 1 << 12;
int tr[N][26], ne[N], idx, q[N], st[N], v[N], f[N][M], pre1[N][M], pre2[N][M];
int n;
char s[55];

void insert(int k){
    int p = 0;
    for (int i = 0; s[i]; i ++){
        int c = s[i] - 'A';
        if (!tr[p][c]) tr[p][c] = ++ idx, v[idx] = c;
        p = tr[p][c];
    }
    st[p] += 1 << k;
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
            if (!c) tr[t][i] = tr[ne[t]][i];
            else {
                ne[c] = tr[ne[t]][i];
                st[c] |= st[ne[c]];
                q[ ++ tt] = c;
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        scanf("%s", s);
        insert(i);
    }
    build();
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    queue<int> q1, q2;
    q1.push(0), q2.push(0);
    while (!q1.empty()){
        int t1 = q1.front(), state = q2.front();
        q1.pop(), q2.pop();
        if (state == (1 << n) - 1){
            int ans[N], tot = 0;
            while (t1){
                ans[++ tot] = v[t1];
                int x = t1;
                t1 = pre1[x][state], state = pre2[x][state];
            }
            for (int i = tot; i ; i --) printf("%c", ans[i] + 'A');
            return 0;
        }
//         if (state > 0) cout << "v[t1] " << v[t1] << " " << state << endl;
        for (int i = 0; i < 26; i ++){
            int p = tr[t1][i], status = st[p] | state;
            if (f[p][status] == 0x3f3f3f3f){
                f[p][status] = f[t1][state] + 1;
                pre1[p][status] = t1, pre2[p][status] = state;
                q1.push(p), q2.push(status);
            }
        }
    }
    return 0;
}