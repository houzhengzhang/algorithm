// Source : https://www.luogu.org/problemnew/show/P1208
// Date   : 2019-04-13
/**
    混合牛奶 Mixing Milk
根据单价排序后直接求和
*/

#include <iostream>
#include<algorithm>
using namespace std;
#define MAXN 5001
int n,m,i,ans,sum;

struct node
{
    int p,a;
    bool operator<(const node &n) const{return p<n.p;}
} milk[MAXN];

int main()
{
    cin>>n>>m;
    for(i=0; i<m; ++i)
    {
        cin>>milk[i].p>>milk[i].a;
    }
    sort(milk, milk+m);
    i=0;
    while(sum<n){
        if(sum+milk[i].a<=n){
                sum+=milk[i].a;
                ans+=milk[i].p*milk[i].a;
        } else{
            ans+=milk[i].p*(n-sum);
            sum=n;
        }
        ++i;
    }
    cout<<ans<<endl;
    return 0;
}

