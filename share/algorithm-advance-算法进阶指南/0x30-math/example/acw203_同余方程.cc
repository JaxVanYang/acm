#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y, y = z - a / b * y;

    return d;
}

int main() {
    int a, b;
    cin >> a >> b;

    int x, y;

    int d = exgcd(a, b, x, y);

    cout << (x + b) % b << endl;
}