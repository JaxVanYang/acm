/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 19:00:22
 * @LastEditTime: 2021-03-23 19:00:38
 */

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double k,n,s,p;
    cin>>k>>n>>s>>p;
    cout<<int(ceil(ceil(n/s)*k/p));
    return 0;
}