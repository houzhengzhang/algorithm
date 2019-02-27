// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1140
// Date   : 2019-02-27

/**
  递推 数的划分问题一
题目描述
把正整数N分解成M个正整数的和，即使M个数相同但顺序不同也认为是不同的方案，
要求总方案数。如3=1+2跟3=2+1是两个不同的方案。
输入
第一行包含两个整数N和M(1<=M<=N<=50)。

输出
输出一个数表示方案数。
样例输入
3 2
样例输出
2
*/

/*
分析见solution.md
递推式：
    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
**/

#include<iostream>
using namespace std;
int n,m,i,j;
#define N 51
long long dp[N][N];

long long func()
{
    for(i=0;i<N;++i)
        dp[i][i]=dp[i][0]=1;
    for(int i=1;i<N;++i)
        for(int j=1;j<N;++j)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
}

int main()
{
    func();
    cin>>n>>m;
    cout<<dp[n-1][m-1]<<endl;
	return 0;
}

