/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-07 19:29:16
 * @LastEditTime: 2021-04-07 20:29:42
 */

#include <iostream>
#include <set>

using namespace std;

string a;
set<char> s{'a', 'e', 'i', 'o', 'u'};
int main(){

    cin >> a;
    for (int i = 0; i < a.size(); i ++){
        if (a[i] == 'n') continue;
        if (!s.count(a[i]) && (i == a.size() - 1 || !s.count(a[i + 1]))){
            puts("NO");
            return 0;
        }
    }    
    puts("YES");

    return 0;
}