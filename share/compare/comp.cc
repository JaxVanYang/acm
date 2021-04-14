/* 
 * 对拍器: comp 取 compare 的缩写
 * 
 * 使用方法：
 * 1. 准备好待测试的代码（sol.cc）、答案代码（ans.cc）、随机数据生成代码（rand.cc）
 * 2. 键入命令：make run
 * 
 * 注意事项：
 * 1. 需配合 Makefile 食用
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
using ll = long long;

int main(const int argc, const char *argv[]) {
    string cur = "./";
    int time = 1e4;
    
    for (int i = 1; i <= time; ++i) {
        system("./rand.out");
        
        double st = clock();
        system("./sol.out < data.in > data.out");
        double ed = clock();
        system("./ans.out < data.in > data.ans");
        if (system("diff data.out data.ans")) {
            puts("WA");
            return 0;
        } else {
            printf("AC, Test case #%d, time %.01fms\n", i, ed - st);
        }
    }
}