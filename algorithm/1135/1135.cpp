// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1135
// Date   : 2019-02-19

/**
  递推 错排问题
题目描述
n个编号为1到n的同学手里都有一本书，n本书互不相同，现在把这n本书收起来，再重新分发给同学，
要求每个同学必须都有书，并且每个同学现在拿到的书必须不同于之前手里的那本书，问有多少种分发方案？
如n=3有两种分发方案：2 3 1和3 1 2。

输入
第一行输入一个正整数n(1<=n<=20)。

输出
输出一个整数表示方案数。

样例输入
3
样例输出
2
*/

/*
首先考虑第一个元素a1，它的位置可以有n-1种选择，假设将其放在第i个位置，则对于第i个元素有两种选择：
    （1）i放在a1的位置，此时方案数为D(n-2)
    （2）i不放在a1的位置，即i成为新的a1，此时方案数为D(n-1)
所以，递推公式为：D(n)=(n-1)(D(n-1) + D(n-2))
**/

#include<iostream>
using namespace std;
int n,i;
long long d[21];
int main()
{
    d[1]=0;
    d[2]=1;
    cin>>n;
    for(i=3;i<=n;++i)
        d[i]=(i-1)*(d[i-1] + d[i-2]);
    cout<<d[n]<<endl;
	return 0;
}
