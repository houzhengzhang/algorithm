// Source : https://www.luogu.org/problemnew/show/P1219
// Date   : 2019-04-24
/**
    dfs 八皇后
深搜 + 回溯
使用x[i]=j表示第i行第j列放置皇后，在check时会循环判断超时
bool check(int cur)
{
    for(int i=0; i<cur; ++i)
    {
        if(x[i]==x[cur] || (abs(i-cur)==abs(x[i]-x[cur])))
            return false;
    }
    return true;
}

flags[0][i]=1;  // 记录列
flags[1][cur+i]=1;  // 记录左上角到右下角
flags[2][cur-i+n]=1;  // 记录右上角到左下角
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 15

int n,num,x[N];
int flags[3][50]= {0};


void dfs(int cur)
{
    if(cur>=n)
    {
        num++;
        if(num<=3)
        {
            for(int i=0; i<n; ++i)
                printf("%d ",x[i]+1);
            printf("\n");
        }
        return;
    }
    else
    {
        for(int i=0; i<n; ++i)
        {
            if( (!flags[0][i]) && (!flags[1][cur+i]) && (!flags[2][cur-i+n]) )
            {
                x[cur]=i;

                flags[0][i]=1;  // 记录列
                flags[1][cur+i]=1;  // 记录左上角到右下角
                flags[2][cur-i+n]=1;  // 记录右上角到左下角

                // 搜索下一个位置
                dfs(cur+1);

                // 清除状态，回溯
                flags[0][i]=0;
                flags[1][cur+i]=0;
                flags[2][cur-i+n]=0;
            }
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    cout<<num<<endl;
    return 0;
}

