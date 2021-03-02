/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-25 19:26:04
 * @LastEditTime: 2021-02-25 19:26:05
 */

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> PII;
const int N = 1000000;


int primes[N], cnt;     
bool st[N];         

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    int T;
    cin >> T;
    get_primes(N);

    while (T --){
        int a;
        cin >> a;
        PII res = {0x3f3f3f3f, -1};
        for (int i = 0; i < cnt; i ++){
            int t = a, u = primes[i],ans = 0;
            for (int j = 0; j <= 6 && t > 0 && u > 0; j ++){
                ans += abs((t % 10) - (u % 10));
                t /= 10, u /= 10;
            }
            while (t > 0) ans += t % 10, t /= 10;
            while (u > 0) ans += u % 10, u /= 10;
            if (ans < res.first){
                res.first = ans, res.second = i;
            }
        }
        
        cout << primes[res.second] << endl;
        
    }
    
    
    return 0;
}