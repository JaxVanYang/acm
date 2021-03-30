/*
 * @Descripttion: 排序
 * @Topic link: https://www.acwing.com/problem/content/description/345/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-26 23:26:10
 * @LastEditTime: 2021-03-28 11:02:07
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 27;
int n, m;
bool st[N];
int d[N][N], g[N][N];

void floyd(){ // 跑floyd，d[i][j] == 1表示i<j,通过floyd传递闭包
    memcpy(d, g, sizeof d);
    for (int k = 0; k < n; k ++){
        for (int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                d[i][j] |= d[i][k] & d[k][j]; // 关键操作
            }
        }
    }
}

void print(){ // 调试代码
    for (int i = 0; i < n; i ++){
        for (int j = 0; j <n; j ++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int check(){
    for (int i = 0; i < n; i ++) 
        if (d[i][i]) return 2; // 若传递完闭包后出现自己小于自己，则找到矛盾
    
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j ++){
            if (!d[i][j] && !d[j][i]){ // 若存在d[i][j]与d[j][i]均为0，说明二者大小关系不确定
                return 0;
            }
        }
    }
    
    return 1; // 大小关系均确定且不存在矛盾
}

char get_min(){
    for (int i = 0; i < n; i ++){
        if (st[i]) continue;
        bool tag = true;
        for (int j = 0; j < n; j ++){
            if (!st[j] && d[j][i]){ // 如果j并未输出且j比i小，失败，退出
                tag = false;
                break;
            }
        }
        if (tag) {
            st[i] = true;
            return i + 'A';
        }
    }
}

int main(){
    
    while (scanf("%d%d", &n, &m), n || m){
        memset(d, 0, sizeof d);
        memset(g, 0, sizeof g);
        int type = 0, t = 0; // type记录答案类型，t为迭代次数，上次错误为未用t记录而是找到答案就退出，
                             //此时不等关系还没读完，导致n，m值不正确
        for (int i = 1; i <= m; i ++){
            char op[5];
            scanf("%s", op);
            int a = op[0] - 'A', b = op[2] - 'A';
            g[a][b] = 1;
            if (!type){ // 只有关系不确定时才进行传递闭包与判断
                floyd();
                type = check();
                if (type) t = i;
            }
        }
        
        if (type == 2) printf("Inconsistency found after %d relations.\n", t);
        else if (!type) printf("Sorted sequence cannot be determined.\n");
        else {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for (int i = 0; i < n; i ++) printf("%c", get_min()); // 每次找最小值输出
            printf(".\n");
        }
    }
    
    return 0;
}
