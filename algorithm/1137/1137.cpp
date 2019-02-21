// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1137
// Date   : 2019-02-21

/**
  递推 出栈序列
题目描述
按照1,2,...,n-1,n的顺序入栈，问可以得到多少种出栈序列。
如n=3时有1 2 3，1 3 2，2 1 3，2 3 1，3 2 1共5种出栈序列。
输入
第一行输入n(1<=n<=30)表示数的个数。

输出
输出一个数表示出栈序列的种数。
样例输入
3
样例输出
5
*/

/*
出栈序列数可以通过卡特兰数递推公式求解，d(n)=(4n-2)/(n+1)d(n-1)
**/

#include<iostream>
using namespace std;
int n;
#define N 31
long long d[N];

long long catalan()
{
    d[1]=1;
    for(int i=2;i<=N;++i)
        d[i]=(4*i-2)*d[i-1]/(i+1);
}

int main()
{
    catalan();
    cin>>n;
    cout<<d[n]<<endl;
	return 0;
}

