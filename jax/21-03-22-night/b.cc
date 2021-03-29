#include <iostream>
using namespace std;
const int maxn = 1005;
int arr[maxn];

int main() {
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int cnt = (n + s - 1) / s;
    int ans = (k * cnt + p - 1) / p;
    cout << ans << endl;
}