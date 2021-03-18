/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 09:49:14
 * @LastEditTime: 2021-03-18 10:20:53
 */

#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 5;
string a;
unordered_map<char, int> m;
unordered_map<int , char> m2;
int cnt = 0;
int main(){

    cin>> a;
    for (int i=0; i < a.size(); i ++){
        if (m.count(a[i]) == 0) m[a[i]] =  1, m2[++ cnt] = a[i];
        else  m[a[i]] ++;
    }
    int k = m.size();
    if  (k > 1 && k < 5){
        if (k == 2){
            for (int i = 1; i <= cnt; i ++){
                if (m[m2[i]] < 2){
                    printf("No\n");
                    return 0;
                }
            }
            printf("Yes\n");
            return 0;
        }
        else if (k == 3){
            bool tag = false;
            for (int i = 1; i<= cnt; i++){
                if (m[m2[i]] >= 2) tag  = true;
            }
            if  (tag) printf("Yes\n");
            else printf("No\n");
            return 0;
        }
        else printf("Yes\n");
        return 0;
    }
    printf("No\n");

    return 0;
}