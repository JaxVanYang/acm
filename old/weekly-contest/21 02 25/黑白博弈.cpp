/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-25 22:31:08
 * @LastEditTime: 2021-02-25 22:31:08
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>;

using namespace std;

const int N = 100010;

int n, m;

int main(){
    set<int> st;
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        char op;
        int p;
        cin >> op >> p;
        if (op == 'B'){
            st.insert(p);
        }
        else if (op == 'W'){
            st.erase(p);
        }
        else {
            auto t = st.lower_bound(p);
            if(st.size() == 0) cout << n << endl;
            else if (*t == p) cout << 0 << endl;
            else {
                if (t == st.end()){
                    cout << n - (*(--st.end())) << endl;
                    continue;
                }
                int x = *t;
                if (t == st.begin()){;
                    cout << x - 1 << endl;
                    continue;
                }
                t --;
                int y = *t;
                cout << x - y - 1 << endl;
            }
        }
    }
    return 0;
}