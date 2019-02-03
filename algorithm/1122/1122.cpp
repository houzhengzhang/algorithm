// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1122
// Date   : 2019-02-03

/**
  递归 黑白棋子的移动

题目描述
有2n个棋子（n≥4）排成一行，开始为位置白子全部在左边，黑子全部在右边，如下图为n=5的情况：
       ○○○○○●●●●●
       移动棋子的规则是：每次必须同时移动相邻的两个棋子，颜色不限，可以左移也可以右移到空
       位上去，但不能调换两个棋子的左右位置。每次移动必须跳过若干个棋子（不能平移），要求
       最后能移成黑白相间的一行棋子。
       如n=5时，成为：○●○●○●○●○●
       任务：编程打印出移动过程。
输入
一个整数

输出
移动过程

样例输入
7
样例输出
step 0:ooooooo*******--
step 1:oooooo--******o*
step 2:oooooo******--o*
step 3:ooooo--*****o*o*
step 4:ooooo*****--o*o*
step 5:oooo--****o*o*o*
step 6:oooo****--o*o*o*
step 7:ooo--***o*o*o*o*
step 8:ooo*o**--*o*o*o*
step 9:o--*o**oo*o*o*o*
step 10:o*o*o*--o*o*o*o*
step 11:--o*o*o*o*o*o*o*
*/

#include <iostream>
using namespace std;
// 记录棋子
char chess[10001];
// 记录空位的起始位置
int space;
int n, count=0;

void print()
{
    cout<<"step "<<count++<<":";
    for(int i=1;i<= 2 * n + 2;++i) cout<<chess[i];
    cout<<endl;
}

void move(int pos)
{
    for(int i=0; i<=1; ++i)
    {
        chess[space + i] = chess[pos + i];
        chess[pos + i] = '-';
    }
    space = pos;
    print();
}
int f(int n)
{
    if(n == 4)
    {
        move(4);move(8);move(2);move(7);move(1);
    }else
    {
        move(n);
        move(2 * n - 1);
        f(n - 1);
    }
}
/**
先从n=4看：
             ○○○○●●●●--
第1步：○○○——●●●○●  {—表示空位}  4
第2步：○○○●○●●——●                8
第3步：○——●○●●○○●                2
第4步：○●○●○●——○●                7
第5步：——○●○●○●○●                1
当n=5时：
            ○○○○○●●●●●--
第1步：○○○○——●●●●○●
第2步：○○○○●●●●——○●
可以看到n=5的问题分解为n=4的问题，即对于规模n的问题可以转化为规模为n-1的问题解决
*/

int main()
{
    cin>>n;
    // 初始化记录数组
    for(int i=1;i<=n;++i)chess[i]='o';
    for(int i=n+1;i<=2*n;++i)chess[i]='*';
    chess[2 *n + 1] = '-';
    chess[2 *n + 2] = '-';
    // 记录空位
    space = 2 * n + 1;
    print();
    f(n);

    return 0;
}
