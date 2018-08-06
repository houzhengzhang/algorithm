* #####  错排问题

  ## 题目描述

  n个编号为1到n的同学手里都有一本书，n本书互不相同，现在把这n本书收起来，再重新分发给同学，要求每个同学必须都有书，并且每个同学现在拿到的书必须不同于之前手里的那本书，问有多少种分发方案？

  如n=3有两种分发方案：2 3 1和3 1 2。

  ## 输入

  **第一行输入一个正整数** **n(1<=n<=20)**

  ## 输出

  输出一个整数表示方案数。

  ## 样例输入

  ```
  3
  ```

  ## 样例输出

  ```
  2
  ```

```
#include <iostream>
#include<iomanip>
using namespace std;

long long d[21];
long long cal(int n)
{
	d[1]=0;
	d[2]=1;
	for(int i=3;i<=n;++i)
		d[i]=(i-1)*(d[i-1]+d[i-2]);

	return d[n];
}
int main()
{
	int n;
	cin>>n;

	cout<<cal(n)<<endl;

    return 0;
}
```

* ##### 核电站问题

  ## 题目描述

  一个核电站有N个放核物质的坑，坑排列在一条直线上。如果连续３个坑中放入核物质，则会发生爆炸，于是，在某些坑中可能不放核物质。现在，请你计算：对于给定的N，求不发生爆炸的放置核物质的方案总数。

  ## 输入

  输入文件只有多行，每行对应一个正整数N＜＝４０；

  ## 输出

  输出文件有多行，每行只有一个正整数，表示方案总数

  ## 样例输入

  ```
  1
  2
  3
  4
  10
  ```

  ## 样例输出

  ```
  2
  4
  7
  13
  504  
  ```

  **分析**

  $f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2]$

  $f[i][1]=f[i-1][0]$

  $f[i][2]=f[i-1][1]$

```
#include <iostream>
#include<cstring>
using namespace std;
#define ll long long
ll f[35][35];

ll calcuate(ll n)
{
	for (int i=0;i<35;++i)
		for (int j=0;j<35;++j)
			f[i][j]=0;

	f[1][0]=1;
	f[1][1]=1;

	f[2][0]=2;
	f[2][1]=1;
	f[2][2]=1;
	int i; 
	for(i=3;i<=n;++i)
	{
		f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2];
		f[i][1]=f[i-1][0];
		f[i][2]=f[i-1][1];
	}
	return f[n][0]+f[n][1]+f[n][2];
}
int main()
{
	int  n;
	while(cin>>n)
	{
		cout<<calcuate(n)<<endl;
	} 
	return 0;
}
```

* ##### 凸多边形划分

  ## 题目描述

  在一个凸n边形中，通过不相交于n边形内部的对角线，把n边形拆分成若干三角形，问有多少种拆分方案。

  例如五边形有如下五种拆分方案。

  ![img](http://122.139.62.222:88/upload/pimg1116_1.jpg)

  ## 输入

  第一行输入一个整数n(3<=n<=32)。

  ## 输出

  输出一个数表示划分方案的总数。

  ## 样例输入

  ```
  5
  ```

  ## 样例输出

  ```
  5
  ```

```
#include <iostream>
#include<cstring>
using namespace std;
#define ll long long
ll f[35];
ll total(int n)
{
	if(f[n])  return f[n];
	ll res=0;
	for (int j=2;j<n;++j)
		res+=total(j)*total(n-j+1);

	return f[n]=res;

}

int main()
{
	for (int i=0;i<35;++i)
		f[i]=0;
	ll n=0;
	f[2]=1;
	f[3]=1;

	cin>>n;
	cout<<total(n)<<endl;

	return 0;
}
```

* ##### 卡特兰数

  ```
  #include <iostream>
  #include<cstring>
  using namespace std;
  #define ll long long
  ll res[35];
  ll caculate(int n)
  {
      if(res[n])  return res[n];
      return  res[n]=(4*n-2)*caculate(n-1)/(n+1);
  }
  
  int main()
  {
      memset(res,0,sizeof(res));
      res[0]=1;
      res[1]=1;
      int n;
      cin>>n;
      cout<<caculate(n)<<endl;
      return 0;
  }
  ```