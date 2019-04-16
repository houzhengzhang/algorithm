// Source : https://www.luogu.org/problemnew/show/P1223
// Date   : 2019-04-15
/**
    排队接水
利用pair记录第i个人和接水时间，按升序进行排序
排序后等待时间 a[i].first*(n-i-1) 累加求和
*/

#include <iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n,i,x;
double ans;

int main()
{
    cin>>n;
    pair<int, int> *a = new pair<int, int>[n];
    for(i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    for(i=0;i<n;++i){
        cout<<a[i].second<<" ";
        ans += (a[i].first)*(n-i-1);
    }
    cout<<endl<<fixed<<setprecision(2)<<ans/2<<endl;

    return 0;
}

