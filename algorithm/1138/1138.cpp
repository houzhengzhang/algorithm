// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1138
// Date   : 2019-02-25

/**
  递推 加括号
题目描述
 对于a0*a1*a2*...*an-1*an，可以通过添加改变运算顺序。问有多少种不同的运算顺序？
    如n=3时，用1,2,3表示一开始从做到右出现的乘号的编号，通过添加括号有以下5种运算顺序：
    1 2 3:a0*a1*a2*a3
    1 3 2:a0*a1*(a2*a3)
    2 1 3:a0*(a1*a2)*a3
    2 3 1:a0*(a1*a2*a3)
    3 2 1:a0*(a1*(a2*a3))

输入
输入n表示n个乘号，即n+1个数连乘。
输出
输出一个数表示有多少种不同的运算顺序。
样例输入
3
样例输出
5
提示
n<=30
*/

/*
方法一：
    状态:f[i]表示i个乘号通过添加括号后运算顺序数
    考虑最后一次进行的是哪一个乘法来分析递推关系式，如果最后进行
    的是第j个乘号（第一个到第j-1个添加一对括号，第j+1个到第i个添加
    一对括号就可以保证第j个乘号最后进行），则左边j-1个乘号的运算顺序
    为f[j-1]，右边i-j个乘号的运算顺序为f[i-j]，利用乘法原理和加法原
    理可以得到以下递推关系式:
                            f[i] = ∑_{j=1}^{i} f[j-1]*f[i-j] if i>=1
                            f[i] = 1 if i=0
    此方法的时间复杂度为O(n^2)
方法二：
    方法一中得到的递推式为卡特兰数的定义式，故可以
    通过卡特兰数递推公式求解，d(n)=(4n-2)/(n+1)d(n-1)，时间复杂度可以降到O(n)
**/

// 方法一
#include<iostream>
using namespace std;
int n;
#define N 31
long long f[N];

long long catalan()
{
    f[0]=1;
    for(int i=1;i<N;++i)
        for(int j=1;j<=i;++j)
            f[i] += f[j-1]*f[i-j];
}

int main()
{
    catalan();
    cin>>n;
    cout<<f[n]<<endl;
	return 0;
}

/*
方法二
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
**/

