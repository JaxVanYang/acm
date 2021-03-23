/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/description/160/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-19 10:08:56
 * @LastEditTime: 2021-03-19 10:09:21
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e6  + 5;

char a[N], b[N];
int  n;

int get_min(char s[]){
    int i = 0, j = 1;
    while(i < n && j < n){
        int k=0;
        while  (k < n && s[i + k] == s[j + k]) k ++;
        if (k == n) break;
        if  (s[i  +  k] > s[j  + k])  i += k + 1;
        else j += k  + 1;
        if (i == j) j ++;
    }
    int t = min(i, j);
    s[t + n]  = 0;
    // cout << t << endl;
    return t;
}

int main(){
    
    scanf("%s%s", a, b);
    n = strlen(a); 
    // cout << n << endl;
    memcpy(a + n, a, n); // 注意memcpy的用法
    memcpy(b + n, b, n);
    int pa = get_min(a), pb = get_min(b);
    // cout <<  pa <<  " " << pb << endl;
    if (strcmp(a + pa, b + pb))  puts("No");
    else {
        puts("Yes");
        puts(a + pa);
    }
    
    return 0;
}