// Source : https://www.luogu.org/problemnew/show/P1551
// Date   : 2019-05-15
/**
    并查集 亲戚

最基础的并查集
路径优化 按秩合并
*/

#include<iostream>
using namespace std;
#define N 5000+5
int n,m,p,x,y;

struct union_set
{
    int disjoint[N], rank[N];
    union_set()
    {
        for(int i=0; i<N; ++i)
        {
            disjoint[i]=i;
            rank[i]=0;
        }

    }
    // 查找时进行路径压缩
    int find_set(int x)
    {
        return disjoint[x]==x?x:disjoint[x]=find_set(disjoint[x]);
    }
    void merge(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        // 按秩合并 将秩小的合并到秩大的下面
        if(rank[x]>rank[y])
            // 因为y比x矮合并后不会增加x的高度
            disjoint[y]=x;
        else
        {
            // rank[x]<rank[y] 因为x比y矮合并后不会增加y的高度
            disjoint[x]=y;
            if(rank[x]==rank[y])
                // 两高度相同，合并后秩增加1
                rank[y]++;
        }
    }
} u_set;

int main()
{

    cin>>n>>m>>p;
    while(m--)
    {
        cin>>x>>y;
        u_set.merge(x,y);
    }
    while(p--)
    {
        cin>>x>>y;
        // 查找两人的祖先是否相同
        if(u_set.find_set(x)==u_set.find_set(y))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}

