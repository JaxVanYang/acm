#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int k;
    ans += n / 100;
    n -= n / 100 * 100;
    ans += n / 20;
    n -= n / 20 * 20;
    ans += n / 10;
    n -= n / 10 * 10;
    ans += n / 5;
    n -= n / 5 * 5;
    ans += n;
    cout << ans << endl;
}