// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1121
// Date   : 2019-02-01

/**
  递归 集合的划分

题目描述
设ｓ是一个具有n个元素的集合，ｓ＝｛a1，a2，……，an｝，现将ｓ划分成K个满足下列条件的子集合s1，s2，……，sk ，且满足：
        1．si≠φ
        2．si∩sj＝φ         (1≤i，j≤k  i≠j)
        3．s1∪s2∪s3∪…∪sk＝ｓ
则称s1，s2，……，sk是集合ｓ的一个划分。它相当于把ｓ集合中的n个元素a1 ，a2，……，an 放入k个（0<k≤n<30）无标号的盒子中，
使得没有一个盒子为空。请你确定n个元素a1 ，a2 ，……，an 放入k个无标号盒子中去的划分数s(n，k)。
输入
一行两个整数n、k

输出
一行，一个整数s(n,k)

样例输入
10 6
样例输出
22827
*/

#include <iostream>
using namespace std;

int f(int n, int k)
{
    if(n<k || k==0)
        return 0;
    if(k==n || k==1)
        return 1;

    return f(n-1, k-1) + k * f(n-1, k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<f(n, k);
    return 0;
}
