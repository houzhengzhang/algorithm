// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1139
// Date   : 2019-02-26

/**
  递推 凸多边形划分
题目描述
在一个凸n边形中，通过不相交于n边形内部的对角线，把n边形拆分成若干三角形，问有多少种拆分方案。
例如五边形有如下五种拆分方案。

输入
第一行输入一个整数n(3<=n<=32)。
输出
输出一个数表示划分方案的总数。
样例输入
5
样例输出
5
*/

/*
分析见solution.md
递推式：
            1    if n=2
    f[n]=   ∑_{i=2}^{n-1} f[i]*f[n-i+1]    if n>2

**/

#include<iostream>
using namespace std;
int n,i,j;
#define N 33
long long f[N];

long long calculate(int n)
{
    f[2]=f[3]=1;
    for(int i=4;i<=n;++i)
        for(int j=2;j<i;++j)
            f[i] += f[j]*f[i-j+1];
}

int main()
{
    cin>>n;
    calculate(n);
    cout<<f[n]<<endl;
	return 0;
}
