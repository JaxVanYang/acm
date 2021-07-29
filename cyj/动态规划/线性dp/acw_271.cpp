/*
 * @Descripttion: 杨老师的照相排列 轮廓的进展就是阶段的推移
 * 之前因为f过大后使用memset超时，所以把f开得刚好够用就行了
 * @Topic link: https://www.acwing.com/problem/content/273/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-09 10:46:20
 * @LastEditTime: 2021-04-09 11:48:57
 */

#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 31;

int a[6];
int k;

int main(){
    
    while (cin >> k, k){
        for (int i = 1; i <= k; i++) cin >> a[i];
	    while (k < 5) a[++k] = 0;
	    LL f[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];
	    memset(f, 0, sizeof(f));
        f[0][0][0][0][0] = 1;
        for (int a1 = 0; a1 <= a[1]; a1 ++){
            for (int a2 = 0; a2 <= a[2]; a2 ++){
                for (int a3 = 0; a3 <= a[3]; a3 ++){
                    for (int a4 = 0; a4 <= a[4]; a4 ++){
                        for (int a5 = 0; a5 <= a[5]; a5 ++){
                            LL t = f[a1][a2][a3][a4][a5];
                            if (f[a1][a2][a3][a4][a5] == 0) continue;
                            if (a1 < a[1]) f[a1 + 1][a2][a3][a4][a5] += t;
                            if (a2 < a[2] && a2 < a1) f[a1][a2 + 1][a3][a4][a5] += t;
                            if (a3 < a[3] && a3 < a2) f[a1][a2][a3 + 1][a4][a5] += t;
                            if (a4 < a[4] && a4 < a3) f[a1][a2][a3][a4 + 1][a5] += t;
                            if (a5 < a[5] && a5 < a4) f[a1][a2][a3][a4][a5 + 1] += t;
                        }
                    }
                }
            }
        }

        cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
    }
    return 0;
}


