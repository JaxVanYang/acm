/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/21337
来源：牛客网

牛牛喜欢回文串，牛妹给了牛牛一个字符串S，牛牛想把S变成回文串
牛牛可以做如下三种操作
1：在任意位置增加一个字符
2：删除一个字符
3：改变一个字符

每种操作都有限定的字符，比如，只能删除'a',增加'b',把'c'变成'd'等等
每种操作都有相应的代价
用M条语句来描述能进行的操作
add c x 表示增加c字符需要x的代价
erase c x表示删除c字符需要x的代价
change c1 c2 x表示将c1 改成c2需要x的代价
求牛牛想要得到回文串需要的最少代价
如果不行输出-1

区间dp，f[i][j] 可由 f[i+1][j], f[i][j-1], f[i+1][j-1]得到,但由于有多条转换规则，
通过最短路思想求出每一个字母变换为回文串的最小代价，转移时选择代价最小的方式转移即可

 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-14 16:53:44
 * @LastEditTime: 2021-07-14 17:05:22
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 55;
const long long inf = 1e14;
long long c_add[30], c_era[30], c[30][30], C[27], f[N][N];

void init(){
    for (int i = 0; i < 26; i ++){
        c_add[i] = c_era[i] = C[i] = inf;
        for (int j = 0; j < 26; j ++){
            if (i == j) continue;
            c[i][j] = inf;
        }
    }
}

void floyd(){
    for (int i = 0; i < 26; i ++){
        for (int j = 0; j < 26; j ++){
            for (int k = 0; k < 26; k ++){
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
            }
        }
    }
    for (int i = 0; i <26; i ++) {
        C[i] = min(C[i], min(c_add[i], c_era[i]));
        for (int j = 0; j < 26; j ++){
            C[i] = min(C[i], c_add[j] + c[j][i]);
            C[i] = min(C[i], c[i][j] + min(c_add[j], c_era[j]));
            for (int k = 0; k < 26; k ++){
                C[i] = min(C[i], c[i][j] + c_add[k] + c[k][j]);
            }
        }
    }
}

int main(){
    int m;
    char x, y, s[N];
    scanf("%s",s + 1);
    cin >> m;
    int n = strlen(s + 1);
    long long cost;
    init();
    while ( m -- ){
        char op[10];
        scanf("%s", op), getchar();
        if (*op == 'a'){
            scanf("%c %lld", &x, &cost), c_add[x - 'a'] = min(c_add[x-'a'], cost);
        }
        else if (*op == 'e'){
            scanf("%c %lld", &x, &cost), c_era[x-'a'] = min(c_era[x-'a'], cost);
        }
        else {
            scanf("%c %c %lld", &x, &y, &cost), c[x-'a'][y-'a'] = min(c[x-'a'][y-'a'], cost);
        }
    }

    floyd();
    for (int len = 1; len <= n; len ++){
        for (int l = 1; l + len - 1 <= n; l ++){
            int r = l + len - 1;
            f[l][r] = inf;
            if (len == 1){
                f[l][l] = 0;
                continue;
            }            
            if (s[l] == s[r]) f[l][r] = f[l+1][r-1];
            f[l][r] = min(f[l][r], f[l+1][r] + C[s[l] - 'a']);
            f[l][r]  =min(f[l][r], f[l][r-1] + C[s[r] - 'a']);
            f[l][r] = min(f[l][r], f[l+1][r-1] + min(c[s[l]-'a'][s[r]-'a'], c[s[r]-'a'][s[l]-'a']));
            // 之前错误处: 之前初始化时把f[i][j] (j < i) 全初始化为了inf，而此处第三条变化时若r=l+1 -> (l+1 > r-1)，则转换作废
            for (int k = 0; k < 26; k ++){
                f[l][r]  =min(f[l][r], f[l + 1][r-1] + c[s[l]-'a'][k] + c[s[r]-'a'][k]);
            }
        }
    }
    if (f[1][n] == inf) puts("-1");
    else printf("%lld", f[1][n]);
    return 0;
}