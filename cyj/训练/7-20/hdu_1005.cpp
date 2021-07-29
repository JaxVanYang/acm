/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-20 12:27:58
 * @LastEditTime: 2021-07-20 13:55:22
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e7+5;
typedef long long ll;
int primes[1000000], cnt;
bool st[N];
ll s[N];

void init(){
    for (int i = 2; i <= 10000000; i ++){
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= 10000000 / i; j ++){
            st[i * primes[j]] = 1;
            if ((i % primes[j]) == 0) break;
        }
    }
}

int main(){
    int T;
    init();
    cin >> T;
    for (int i = 3; i < 10000000; i ++){
        if (st[i]){
            s[i] = s[i-1] + i;
        }else s[i] = s[i-1] + 2 * i;
    }
    while (T --){
        int x;
        cin >> x;
        cout << s[x] << endl;
    }
    return 0;
}