/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 10:43:08
 * @LastEditTime: 2021-03-14 10:43:09
 */

#include <iostream>
#include <cstring>

using namespace std;

int T, n;

int main(){
    
    cin >> T;
    while (T -- ){
        cin >> n;
        int t = n;
        int k = 0;
        while (t){
            t >>= 1;
            k ++;
        }

        cout << n - 1 - (1<<(k - 1)) + 1 << endl;
    }
    
    return 0;
}