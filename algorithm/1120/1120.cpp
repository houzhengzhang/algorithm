// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1120
// Date   : 2019-01-25

/**
  递归 双色汉诺塔

题目描述
      设A、B、C是3个塔座。开始时，在塔座A上有一叠共n个圆盘，这些圆盘自下而上，由大到小地叠在一起。
各圆盘从小到大编号为1，2，……，n，奇数号圆盘着红色，偶数号圆盘着蓝色，如图所示。现要求将塔座A上的这
一叠圆盘移到塔座B上，并仍按同样顺序叠置。在移动圆盘时应遵守以下移动规则：
    规则(1)：每次只能移动1个圆盘；
    规则(2)：任何时刻都不允许将较大的圆盘压在较小的圆盘之上；
    规则(3)：任何时刻都不允许将同色圆盘叠在一起；
    规则(4)：在满足移动规则(1)-(3)的前提下，可将圆盘移至A，B，C中任一塔座上。
试设计一个算法，用最少的移动次数将塔座A上的n个圆盘移到塔座B上，并仍按同样顺序叠置。

编程任务：对于给定的正整数n，编程计算最优移动方案。

输入
正整数n。


输出
若干行。每一行由一个正整数k和2个字符c1和c2组成，表示将第k个圆盘从塔座c1移到塔座c2上。

样例输入
3
样例输出
1 A B
2 A C
1 B C
3 A B
1 C A
2 C B
1 A B
*/

#include <iostream>
using namespace std;

void move(int n,char source, char target)
{
    cout<<n<<" "<<source<<" "<<target<<endl;
}

void hanoi(int n, char source, char temp, char target)
{
/**
    采用递归方式解决汉诺塔问题，可以分解为三个步骤：
    1）借助target将source上的n-1个圆盘移动到temp上
    2）将最大的圆盘从source移动到target
    3）将temp上的n-1个圆盘移动到target上
*/
    if(n==1)
        move(n, source, target);
    else{
        hanoi(n-1, source, target, temp);
        move(n, source, target);
        hanoi(n-1, temp, source, target);
    }
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}
