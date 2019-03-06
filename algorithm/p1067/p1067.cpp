// Source : https://www.luogu.org/problemnew/show/P1067
// Date   : 2019-03-06

/**
  模拟 多项式输出


输入输出格式
输入格式：
输入共有 2 行

第一行 1 个整数，n，表示一元多项式的次数。
第二行有n+1个整数，其中第i个整数表示第 n-i+1n−i+1 次项的系数，每两个整数之间用空格隔开。
输出格式：
输出共 1行，按题目所述格式输出多项式。

输入输出样例
输入样例#1：
5
100 -1 1 -3 0 10
输出样例#1：
100x^5-x^4+x^3-3x^2+10
输入样例#2：
3
-50 0 0 1
输出样例#2：
-50x^3+1
说明

对于100%数据，0≤n≤100,-100, −100≤系数 ≤100
*/


#include <iostream>
using namespace std;
#define N 101

int res[N];
int n=0,i;


int main()
{
    cin>>n;

    for(i=0; i<=n; ++i) cin>>res[i];

    for(i=0; i<n-1; ++i)
    {
        if(res[i]>0&&i>=1)
            cout<<"+";
        if(res[i]==1) cout<<"x^"<<n-i;
        else if(res[i]==-1) cout<<"-x^"<<n-i;
        else if(res[i]!=0) cout<<res[i]<<"x^"<<n-i;
    }
    if(res[n-1]<0)
    {
        if(res[n-1]==-1) cout<<"-x";
        else cout<<res[n-1]<<"x";
    }else if(res[n-1]>0)
    {
        if(res[n-1]==1) cout<<"+x";
        else cout<<"+"<<res[n-1]<<"x";
    }

    if(res[n]<0)cout<<res[n];
    else if(res[n]>0)cout<<"+"<<res[n];

    cout<<endl;
    return 0;
}

