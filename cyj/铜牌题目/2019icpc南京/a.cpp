/*
 * @Descripttion: 
 Given a positive integer n, you need to find out the minimum integer k
 such that for any subset T of the set {1,2,...,n} of size k, t
 here exist two different integers u,v in T,u,v∈T that u is a factor of v.
 * @Topic link: https://nanti.jisuanke.com/t/42395
 * @Question meaning: 找规律，只要找出的集合中必存在两个数是两倍关系的即可
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-24 20:39:32
 * @LastEditTime: 2021-10-24 20:41:41
 */

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T --){
        int n;
        cin >> n;
        cout << (n+1)/2 + 1 << endl;
    }
    return 0;
}

