// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1136
// Date   : 2019-02-20

/**
  递推 核电站问题
题目描述
一个核电站有N个放核物质的坑，坑排列在一条直线上。如果连续３个坑中放入核物质，则会发生爆炸，
于是，在某些坑中可能不放核物质。现在，请你计算：对于给定的N，求不发生爆炸的放置核物质的方案总数。

输入
输入文件只有多行，每行对应一个正整数N＜＝４０；

输出
输出文件有多行，每行只有一个正整数，表示方案总数

样例输入
1
2
3
4
10
样例输出
2
4
7
13
504
*/

/*
设f[i][j]表示前i个坑最后连续放了j个核物质的方案数
则有f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2]
    f[i][1]=f[i-1][0]
    f[i][2]=f[i-1][1]
**/

#include<iostream>
using namespace std;
int n,i,j;
#define N 41
long long f[N][3];

void calculate()
{
    f[0][0]=f[1][0]=f[1][1]=1;
    f[1][2]=0;
    for(i=2;i<=N;++i)
    {
        f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2];
        f[i][1]=f[i-1][0];
        f[i][2]=f[i-1][1];
    }
}

int main()
{
    calculate();
    while(cin>>n)
        cout<<f[n][0]+f[n][1]+f[n][2]<<endl;
	return 0;
}

