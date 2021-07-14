#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    char ch;
    stack<char> stk;
    while (n--) {
        cin >> ch;
        if (ch == 'R' && stk.size() && stk.top() == 'U') {
            stk.pop();
            stk.push('D');
        } else if (ch == 'U' && stk.size() && stk.top() == 'R') {
            stk.pop();
            stk.push('D');
        } else {
            stk.push(ch);
        }
    }
    cout << stk.size() << endl;
}