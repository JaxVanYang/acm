#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<time.h>
#include<stack>
using namespace std;
#define N 120000
#define INF 0x3f3f3f3f

char a[120][120];

int judge(int x,int y)
{
    int i,j;

    for(i=0;i<4;i++)///列判断，不能有相同的数字
    if(a[x][i]==a[x][y]&&i!=y)
    return 0;

    for(i=0;i<4;i++)///行判断，不能有相同的数字
    if(a[i][y]==a[x][y]&&i!=x)
        return 0;

    int row=x;
    int col=y;
    if(x%2==1)x-=1;///找到小矩阵的左上角
    if(y%2==1)y-=1;

    for(i=x;i<=x+1;i++)///小矩阵判断，不能有相同的数字
        for(j=y;j<=y+1;j++)
        if(a[i][j]==a[row][col]&&i!=row&&j!=col)
        return 0;

    return 1;
}

void dfs(int x)///回溯dfs
{
    int i,j;

    if(x==4*4)///如果遍历了所有点，就输出最终图形
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                printf("%c", a[i][j]);
                printf("\n");
        }
        return ;
    }

    int row=x/4;///行的计算方法
    int col=x%4;///列的计算方法

    if(a[row][col]=='*')
    {
        for(j=1;j<=4;j++)///枚举4个数字
        {
            a[row][col]=j+'0';
            if(judge(row,col))///如果当前这个点符合规则
                dfs(x+1);///进行下一步
            a[row][col]='*';///记得要取消标记。（深搜尝试问题，涉及回溯）
        }
    }
    else///如果不是，跳过，进行下一步
        dfs(x+1);
}

int main()
{
    int T,k=1,i;

    scanf("%d", &T);

    while(T--)
    {
      for(i=0;i<4;i++)
        scanf("%s", a[i]);

      printf("Case #%d:\n", k++);

      dfs(0);
    }
    return 0;
}