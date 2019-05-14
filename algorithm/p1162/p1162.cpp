// Source : https://www.luogu.org/problemnew/show/P1162
// Date   : 2019-05-14
/**
    dfs 填充颜色

深搜，因为只有一个闭合的0的区域，所以先标记边界的0，然后输出判断
*/

#include<iostream>
using namespace std;
#define N 30+5
int n, map[N][N],dx[4]= {0,0,-1,1},dy[4]= {1,-1,0,0}; // 上下左右

void dfs(int x,int y)
{
    // 越界或遇到墙
    if(x>n+1||y>n+1||x<0||y<0||map[x][y])
        return;
    // 标记0的位置为-1
    map[x][y]=-1;
    // 搜索四个方向
    for(int i=0; i<4; ++i)
        dfs(x+dx[i],y+dy[i]);
}


int main()
{
    cin>>n;
    // 从1开始，处理左上角为墙的情况
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin>>map[i][j];

    dfs(0,0);
    // -1的位置输出 0    0的位置输出 2
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            if(map[i][j]==0)
                cout<<2<<" ";
            else if(map[i][j]==-1)
                cout<<0<<" ";
            else cout<<1<<" ";
        cout<<endl;
    }
    return 0;
}

