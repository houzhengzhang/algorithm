// Source : https://www.luogu.org/problemnew/show/P3366
// Date   : 2019-05-16
/**
    最小生成树

*/

#include<iostream>
#include<algorithm>
using namespace std;

#define N 5000+5
#define M 200000+5

int n,m,ans,num;

struct node{
    int x,y,len;
    node():x(0),y(0),len(0){}
    bool operator<(const node& n)const{
        return len<n.len;
    }
}edge[M];

struct union_set{
    int fa[N],rank[N];
    union_set(){
        for(int i=0;i<N;++i){
            fa[i]=i;
            rank[i]=0;
        }
    }
    // 路径压缩
    int find_set(int x){
        return x==fa[x]?x:fa[x]=find_set(fa[x]);
    }

    bool merge(int x,int y){
        x = find_set(x);
        y = find_set(y);
	// 按秩合并
        if(rank[x]>rank[y])
            fa[y]=x;
        else{
            fa[x]=y;
            if(rank[y]==rank[x])
                rank[y]++;
        }
        // 返回是否合并
        return x!=y;
    }
}u_set;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i)
        cin>>edge[i].x>>edge[i].y>>edge[i].len;
    // 按长度升序排序
    sort(edge, edge+m);

    for(int i=0;i<m;++i){
        // 添加边
        if(u_set.merge(edge[i].x, edge[i].y)){
            ans += edge[i].len;
            num++;
        }
    }
    cout<<ans<<endl;
}

