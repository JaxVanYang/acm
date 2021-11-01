/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-09-06 19:40:27
 * @LastEditTime: 2021-09-06 20:08:05
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e5 + 10;
int d[N], w[N];

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        priority_queue<PII> q;
        int n;
        ll sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++){
            scanf("%d", &w[i]);
            sum += w[i];
        }
        for (int i = 1; i < n; i ++){
            int a, b;
            scanf("%d%d", &a, &b);
            d[a] ++, d[b] ++;
        }
        for (int i = 1; i <= n; i ++) q.push({w[i], i});
        printf("%lld ", sum);
        for (int i = 2; i <= n-1; i ++){
            bool f = 0;
            while (!f){
                auto t = q.top();
                q.pop();
                if (d[t.second] >= 2){
                    sum += t.first;
                    d[t.second] --;
                    q.push(t);
                    f = 1;
                }
            }
            printf("%lld " , sum);
        }
        printf("\n");
        for (int i = 1; i <= n; i ++) d[i] = 0;
    }

    return 0;
}