#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);
    set<int> st1;
    set<vector<ll>> st2;
    while (n--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int dx = x1 - x2, dy = y1 - y2;
        if (dx == 0) st1.insert(x1);
        else {
            ll mod = gcd(dx, dy);
            dx /= mod, dy /= mod;
            // 注意将分母保持为正
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            ll up = (ll)y1 * dx - (ll)x1 * dy;
            ll down = dx;
            mod = gcd(up, down);
            up /= mod, down /= mod;
            if (up < 0) {
                up = -up;
                down = -down;
            }
            st2.insert({dx, dy, up, down});
        }
    }
    printf("%ld", st1.size() + st2.size());
}