/*
 * @Descripttion: 合法括号序列字符串a删除任意个（）后能否和b相同
    注意初始化时的边界即可。
 * @Topic link: https://ac.nowcoder.com/acm/problem/21303
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-10 16:46:07
 * @LastEditTime: 2021-07-10 16:47:08
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

char a[N], b[N];
int f[N][N];

int main(){
    
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int len1 = strlen(a + 1), len2 = strlen(b + 1);
    f[0][0] = 1;
    int x = 0;
    for (int i = 1; i <= len1; i ++){ // 初始化时别忘了边界
        if (a[i] == '(') x ++;
        else x --;
        if (!x) f[i][0] = 1;
    }
    for (int i = 1; i <= len1; i ++){
        for (int j = 1; j <= len2; j ++){
            if (a[i] == b[j]) f[i][j] |= f[i-1][j-1];
            if (a[i] == ')'){
                int k = i-1, cnt = 1;
                while (cnt && k){
                    if (a[k] == '(') cnt --;
                    else cnt ++;
                    k --;
                }
                f[i][j] |= f[k][j];
            }
        }
    }
    if (f[len1][len2]) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
    return 0;
}