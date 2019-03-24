// Source : http://122.139.62.222:88/JudgeOnline/problem.php?id=1161
// Date   : 2019-03-24
/*
分治 取余运算
题目描述
输入三个正整数a,b,c计算a^b mod c。
数据范围：100%的数据满足：a,b,c在longint范围内。
输入
第一行输入三个正整数a,b,c。
输出
输出a^b mod c的值。
样例输入
2 3 5
样例输出
3
**/

#include<stdio.h>
using namespace std;

#define ll long long
ll a,b,c;

ll cal(ll a, ll b, ll c)
{
    if(b==1) return a;
    ll ret = cal(a*a%c, b/2, c);
    if(b%2)
        ret = ret * a % c;
    return ret;
}

int main() {
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", cal(a, b, c));
    return 0;
}

