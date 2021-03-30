#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    // cout << s.length();
    // 处理这些内置类型的 size() 方法的时候要小心，因为返回的是无符号整型，如果使用减法可能会产生溢出
    for (int i = 0; i + 2 < s.length(); ++i) {
        // cout << "i = " << i << " len - 2 = " << s.length() - 2 << endl;
        set<char> st;
        for (int j = 0; j < 3; ++j) if (s[i + j] != '.') st.insert(s[i + j]);
        if (st.size() == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}