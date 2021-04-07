#include <iostream>
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    string ans = "";
    int k = (x + 1) / 2;
    for (int i = 0; i < k; ++i) {
        ans += "01";
    }
    for (int i = k; i < b; ++i) ans += '1';
    if (x & 1) {
        for (int i = k; i < a; ++i) ans = '0' + ans;
    } else {
        if (k < a) for (int i = k; i < a; ++i) ans += '0';
        else {  // 特殊处理，如果 0 的个数不足以再增加一个满足条件的序号
            ans.pop_back();
            ans = '1' + ans;
        }
    }
    cout << ans << endl;
}