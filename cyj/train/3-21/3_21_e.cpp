/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-21 13:20:53
 * @LastEditTime: 2021-03-21 14:37:26
 */
/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-21 13:20:53
 * @LastEditTime: 2021-03-21 13:29:01
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 1e6 + 5, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main()
{
    scanf("%d", &n);
    priority_queue<int> p2;
    priority_queue<int, vector<int>, greater<int>> p1;
    int last = 0; 
    for (int i = 0; i < n; i ++){
        int t;
        scanf("%d", &t);
        t ^= last;
        if (p2.empty()) p2.push(t);
        else {
            if (t < p2.top()) p2.push(t);
            else p1.push(t);
            
            while (p2.size() > p1.size() + 1){
                p1.push(p2.top());
                p2.pop();
            }

            while (p1.size() > p2.size()){
                p2.push(p1.top());
                p1.pop();
            }
        }
        printf("%d\n", p2.top());
        last = p2.top();
    }    
    return 0;
}
