// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1133
// Date   : 2019-02-17

/**
  递推 汉诺塔
汉诺塔由编号为1到n大小不同的圆盘和三根柱子a,b,c组成。开始时，这n个圆盘由大到小依次套在a柱上，
如图所示。要求把a柱上n个圆盘按下述规则移到c柱上：
    (1)一次只能移一个圆盘，它必须位于某个柱子的顶部；
    (2)圆盘只能在三个柱上存放；
    (3)任何时刻不允许大盘压小盘。


将这n个盘子从a柱移动到c柱上，最少需要移动多少次？
*/

/*
移动过程分三步：
    （1）将n-1个圆盘从a借助c移动到b上
    （2）将第n个盘子移动到c上
    （3）将n-1个盘子从b借助a移动到c上
递推公式：F(n) = 2*F(n-1)+1
**/

#include <iostream>
#include<stdio.h>
using namespace std;

#define MAXN 35

int res[MAXN], n;

int main()
{
    res[1]=1;
    cin>>n;
    for(int i=2;i<=n;++i)
        res[i]=2*res[i-1]+1;
    cout<<res[n]<<endl;
    return 0;
}
