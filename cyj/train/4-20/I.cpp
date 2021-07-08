/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-20 14:17:28
 * @LastEditTime: 2021-04-20 14:22:35
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

string line, line1;
int a, b;

int main(){
    cin >> a >> b;
    vector<int> number;
    cin >> line;
    for (auto c : line){
        if (c >= '0' && c <= '9') number.push_back(c - '0');
        else if (c >= 'A' && c <= 'Z') number.push_back(c - 'A' + 10);
        else number.push_back(c - 'a' + 36);
    }
    reverse(number.begin(), number.end());
    vector<int> res;
    while (number.size()){
        int t = 0;
        for (int i = number.size() - 1; i >= 0; i--){
            number[i] += t * a;
            t = number[i] % b;
            number[i] /= b;
        }
        res.push_back(t);
        while (number.size() && number.back() == 0) number.pop_back();
    }
    line1;
    reverse(res.begin(), res.end());
    for (auto c : res){
        if (c <= 9) line1 += char(c + '0');
        else if (c <= 35) line1 += char(c - 10 + 'A');
        else line1 += char(c - 36 + 'a');
    }
    cout << line1 << endl;
    return 0;
}