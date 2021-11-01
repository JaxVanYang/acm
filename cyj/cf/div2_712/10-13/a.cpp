/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-13 22:38:42
 * @LastEditTime: 2021-10-13 23:49:55
 */

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T --){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && b == c){
            cout << 1 << ' ' << 1 << ' ' << 1 << endl;
            continue;
        }
        int maxv = max(max(a, b), c);
        if (a == b){
            if (a == maxv){
                cout << '1' << " 1 " << maxv-c+1<< endl;
            }
            else cout << maxv-a+1 << ' ' << maxv-b+1 << " 0\n";
            continue;
        }
        if (b == c){
            if (b == maxv){
                cout << maxv-a+1 << " 1 " << 1 << endl;
            }
            else cout << "0 " << maxv-b+1 << ' ' << maxv-c+1 << endl;
            continue;

        }
        if (a == c){
            if (a == maxv){
                cout << "1 " << maxv-b+1 << " 1"<< endl;
            }
            else cout << maxv-a+1 << " 0 " << maxv-c+1 << endl;
            continue;
        }
        if (maxv == a) cout << 0 << ' ';
        else cout << maxv-a + 1 << ' ';
        if (maxv == b) cout << 0 << ' ';
        else cout << maxv-b + 1 << ' ';
        if (maxv == c) cout << 0 << ' ';
        else cout << maxv-c + 1 << ' ';
        cout << endl;
    }

    return 0;
}