// Source : https://www.luogu.org/problemnew/show/P1111
// Date   : 2019-05-16
/**
    并查集 修复公路

与kruskal累加求和不同，此题记录最大时间
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000+5
#define M 100000+5
int n,m,ans;
// 记录边数 最少有n-1条边才能走通
int num=0;

struct node
{
    int x,y,t;
    bool operator<(const node& n) const
    {
        return t<n.t;
    }
} edge[M];

struct union_set
{
    int fa[N],rank[N];
    union_set()
    {
        // 初始化并查集
        for(int i=0; i<N; ++i)
        {
            fa[i]=i;
            rank[i]=0;
        }
    }
    int find_set(int x)
    {
        // 路径压缩
        return x==fa[x]?x:fa[x]=find_set(fa[x]);
    }
    bool merge(int x,int y)
    {
        x = find_set(x);
        y = find_set(y);
        // 按秩合并
        if(rank[x]>rank[y])
            fa[y]=x;
        else
        {
            // rank[x]<rank[y]
            fa[x]=y;
            if(rank[x]==rank[y])
                rank[x]++;
        }
        if(x!=y)
        {
            return true;
        }
        return false;
    }
} u_set;


int main()
{

    cin>>n>>m;
    for(int i=0; i<m; ++i)
        cin>>edge[i].x>>edge[i].y>>edge[i].t;
    // 按修复时间升序排序
    sort(edge, edge+m);
    for(int i=0; i<m; ++i)
    {
        // 需要判断是否合并成功，若合并会形成环则返回false
        if(u_set.merge(edge[i].x, edge[i].y))
        {
            // 合并后边数+1
            num++;
            // 与kruskal累加求和不同，此处记录最大时间
            ans = max(ans, edge[i].t);
        }
        // 判断是否都已联通
        if(num>=n-1)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}

