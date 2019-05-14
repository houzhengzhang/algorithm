// Source : https://www.luogu.org/problemnew/show/P1506
// Date   : 2019-05-14
/**
    dfs 拯救oibh总部

深搜，注意边界的处理
*/

#include<iostream>
using namespace std;
#define N 500+5
int x,y,ans;
char ch;
int map[N][N],dx[4]= {0,0,-1,1},dy[4]= {1,-1,0,0}; // 上下左右

void dfs(int m,int n)
{
    // 越界或遇到墙
    if(m>x+1||n>y+1||m<0||n<0||map[m][n])
        return;
    // 标记
    map[m][n]=1;
    // 搜索四个方向
    for(int i=0; i<4; ++i)
        dfs(m+dx[i],n+dy[i]);
}


int main()
{
    cin>>x>>y;
    // 从1开始，处理左上角为墙的情况
    for(int i=1; i<=x; ++i)
        for(int j=1; j<=y; ++j)
        {
            cin>>ch;
            if(ch=='0') map[i][j]=0;
            else map[i][j]=1;
        }

    dfs(0,0);
    // 统计0的数量
    for(int i=0; i<x; ++i)
        for(int j=0; j<y; ++j)
            if(!map[i][j]) ++ans;

    cout<<ans<<endl;
    return 0;
}

