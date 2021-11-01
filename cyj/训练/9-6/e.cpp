/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-09-06 20:51:54
 * @LastEditTime: 2021-09-06 21:58:19
 */

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, mod = 998244353;
int f[N], inf[N], pow2[N];

int qpow(int a, int b, int mod) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ll)ans * a % mod; 
		} 
		a = (ll)a * a % mod;
		b >>= 1;
	}
	return ans;
}

void init() {
	f[0] = inf[0] = pow2[0] = 1; // f是 i! % mod    inf 是 1/i! % mod 
	for (int i = 1; i < N; i++) {
        pow2[i] = (ll)pow2[i-1] * 2 % mod;
		f[i] = (ll)f[i - 1] * i % mod;
		inf[i] = (ll)inf[i - 1] * qpow(i, mod - 2, mod) % mod;
	}
}
int main() {
	init();
	int n, m;
    cin >> n >> m;
    int x = ((ll)f[m] * inf[n-1] % mod * inf[m-n+1] % mod) % mod;
    // 此处为2^(n-3)，选出来组成pair的数左右会重复一次，故需再除2
    cout << (((ll)x * pow2[n-3]) % mod * (n-2) % mod) << endl; 

	return 0;
} 
