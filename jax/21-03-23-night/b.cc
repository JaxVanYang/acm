#include <iostream>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, a, b;
        cin >> n >> a >> b;
        int c = gcd(a, b);
        int cnt = n / c;
        string ans;
        if ((cnt - 2) & 1) {
            // printf("Yuwgna\n");
            ans = "Yuwgna";

        } else {
            // printf("Iaka\n");
            ans = "Iaka";
        }
        printf("Case #%d: %s\n", i, ans.c_str());
    }
}