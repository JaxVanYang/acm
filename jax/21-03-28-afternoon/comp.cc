/* 
 * 使用前需要手动编译答案和解法文件
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using ll = long long;

ll random(ll n) {
    return (ll)rand() * rand() % n;
}

int main() {
    srand((unsigned)time(0));
    for (int i = 1; i <= 1e4; ++i) {
        // 必须每次重新打开，否则就会不停附加到输出文件末尾
        FILE *file = fopen("data.in", "w");
        fprintf(file, "1 %lld", random(1e18));
        fclose(file);   // 必须关闭，否则下面的程序读取到的可能是还未修改的文件
        double st = clock();
        system("./d.out < data.in > data.out");
        double ed = clock();
        system("./d_ans.out < data.in > data.ans");
        if (system("diff data.out data.ans")) {
            puts("WA");
            return 0;
        } else {
            printf("AC, Test case #%d, time %.01fms\n", i, ed - st);
            // system("cat data.in");
            // system("cat data.out");
        }
    }
}