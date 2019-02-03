// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1123
// Date   : 2019-02-03

/**
  递归 新汉诺塔

题目描述
 设有n个大小不等的中空圆盘，按从小到大的顺序从1到n编号。将这n个圆盘任意的迭套在三根立柱上，立柱的编号分别为A、B、C，这个状态称为初始状态。
    现在要求找到一种步数最少的移动方案，使得从初始状态转变为目标状态。
    移动时有如下要求：
    ·一次只能移一个盘；
    ·不允许把大盘移到小盘上面。
     n<=50
输入
第一行是状态中圆盘总数；
第二到第四行分别是初始状态中A、B、C柱上圆盘的个数和从上到下每个圆盘的编号；
第五到第七行分别是目标状态中A、B、C柱上圆盘的个数和从上到下每个圆盘的编号。
输出
每行一步移动方案，格式为：move I from P to Q
最后一行输出最少的步数。
样例输入
5
3 3 2 1
2 5 4
0
1 2
3 5 4 3
1 1
样例输出
move 1 from A to B
move 2 from A to C
move 1 from B to C
move 3 from A to B
move 1 from C to B
move 2 from C to A
move 1 from B to C
7
*/

#include <iostream>
#include<stdio.h>
using namespace std;

#define MAXN 55
int src[MAXN], tar[MAXN];
int ans=0;
const char * alpha = "ABC";

void move(int from, int to)
{
    // from - 待移动圆盘块号
    // to   - 目标柱号  A-1   B-2   C-3
    if(src[from] == to) return;
    for(int i=from - 1; i>0; --i)
        move(i, 6 - src[from] - to);
    printf("move %d from %c to %c\n", from, alpha[src[from]-1], alpha[to-1]);
    src[from]=to;
    ++ans;

}
int main()
{
    int num,m,x;
    cin>>num;
    for(int i=1; i<=3; ++i)
    {
        cin>>m;
        for(int j=1; j<=m; ++j)
        {
            cin>>x;
            src[x]=i;
        }
    }
    for(int i=1; i<=3; ++i)
    {
        cin>>m;
        for(int j=1; j<=m; ++j)
        {
            cin>>x;
            tar[x]=i;
        }
    }
    for(int i=num; i>0; i--)
        move(i, tar[i]);
    cout<<ans<<endl;
    return 0;
}
