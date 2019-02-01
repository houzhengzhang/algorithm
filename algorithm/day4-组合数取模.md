* 取球游戏 - 2950

  ## 题目描述

  桌子上放着N个球，每个球都有一个编号，第i个球的编号为i。

  请你求出一共存在多少种不同的取法，使得取出的M个球编号的最小值恰好为K。由于结果可能很大，请输出结果对109+7（这是一个质数）取模的值。

  ## 输入

  输入数据只有一行，包含三个正整数N、M、K。

  ## 输出

  一个整数，表示取法总数对109+7取模的值。

  ## 样例输入

  ```
  4 2 2
  ```

  ## 样例输出

  ```
  2
  ```

  ```
  
  #include <iostream>
  #include<cstdio>
  using namespace std;
  #define ll long long
  #define MAXN 1000001
  const ll P=1000000007;
  ll a[MAXN];
  ll ans=0;
  
  ll cal(ll a,ll b)
  {
      if(b==1)
          return a;
      else
      {
          ll ret =cal(a*a%P,b/2);
          if(b%2)
              ret=ret*a%P;
          return ret;
      }
  }
  int main()
  {
      int n,m,k;
      int i;
  
      cin>>n>>m>>k;
  
      a[0]=1;
      for(i=1;i<=n;++i)
          a[i]=a[i-1]*i%P;
  
      n=n-k;
      m=m-1;
  
      ans=a[n]*cal(a[m],P-2)%P;
      ans=ans*cal(a[n-m],P-2)%P;
  
      cout<<ans<<endl;
      return 0;
  }
  ```

* 组合数取模 - 1971

  ## 题目描述

  计算C（m,n）mod 9901的值

  其中C（m，n）表示m个物品选n个的方案数

  ## 输入

  输入的第一行包含两个整数，m和n

  ## 输出

  输出一行，一个整数

  ## 样例输入

  ```
  2 1
  ```

  ## 样例输出

  ```
  2
  ```

  ## 提示

  ```
  对于 20%的数据，n<=m<=20
  对于 40%的数据，n<=m<=2000
  对于 100%的数据，n<=m<=20000
  ```

  * ##### 分析：

    该题P=9901,直接求阶乘取模会出现阶乘为0，所以需要使用Lucas公式，$C_n^{m}=C_{n/p}^{m/p} * C_{n\%p}^{m\%p}   \%p $  

  ```
  #include <iostream>
  #include<cstdio>
  using namespace std;
  #define ll long long
  #define MAXN 20100
  const ll P=9901;
  ll a[MAXN];
  ll ans=0;
  
  ll cal(ll a,ll b)
  {
      if(b==1)
          return a;
      else
      {
          ll ret =cal(a*a%P,b/2);
          if(b%2)
              ret=ret*a%P;
          return ret;
      }
  }
  
  ll c(ll n,ll m)
  {
      ll ret=0;
  
      ret=a[n]*cal(a[m],P-2)%P;
      ret=ret*cal(a[n-m],P-2)%P;
  
      return ret;
  }
  
  int main()
  {
  
      ll n,m,i;
      a[0]=1;
      // 计算阶乘要%P
      for(i=1;i<=P;++i)
          a[i]=a[i-1]*i%P;
  
      cin>>n>>m;
  
  
      ans=c(n/P,m/P)*c(n%P,m%P)%P;
  
  
      cout<<ans<<endl;
      return 0;
  }
  
  ```

  

  

   





* 生成树 - 1926

  ## 题目描述

  有一种图形叫做五角形圈。一个五角形圈的中心有1个由n个顶点和n条边组成的圈。在中心的这个n边圈的每一条边同时也是某一个五角形的一条边，一共有n个不同的五角形。这些五角形只在五角形圈的中心的圈上有公共的顶点。如图0所示是一个4-五角形圈。

  ![img](http://122.139.62.222:88/JudgeOnline/upload/201601/image/pimg2217_1.jpg)

  现在给定一个n五角形圈，你的任务就是求出n五角形圈的不同生成树的数目。还记得什么是图的生成树吗？一个图的生成树是保留原图的所有顶点以及顶点的数目减去一这么多条边,从而生成的一棵树。由于这样的生成树数目可能过多，你只需要输出答案对998244353的模数即可。

  ## 输入

  一行一个正整数n(n>=2)，代表你需要求解的五角形中心的边数

  ## 输出

  输出一行一个非负整数，表示n五角形圈的生成树数目模998244353之后的结果。

  ## 样例输入

  ```
  2
  ```

  ## 样例输出

  ```
  40
  ```

  * ##### 分析

    通过简单分析可得生成树数目为 $4*n*5^{n-1}$ ，直接使用快速幂求解即可

  * 代码

    ```c++
    #include<cstdio>
    using namespace std;
    #define ll long long
    const ll P=998244353;
    ll n,ans=0;
    
    ll cal(ll a,ll b)
    {
        if(b==1)
            return a;
        ll ret=cal(a*a%P,b/2);
        if(b%2)
            ret=ret*a%P;
        return ret;
    }
    
    int main()
    {
        //n*4*5^(n-1)
        scanf("%lld",&n);
        ans=(n%P*4) *cal(5,n-1)%P;
        printf("%lld",ans);
    
    	return 0;
    }
    ```

* 排列计数 1928

  ## 题目描述

  称一个1,2,...,N的排列P1,P2...,Pn是Magic的，当且仅当2<=i<=N时，P[i]>P[i/2](除法下取整). 计算1，2，...N的排列中有多少是Magic的。

  由于答案可能非常大，你只需要输出答案对998244353的模数即可。

  ## 输入

  一行一个正整数N，含义如题所示。

  ## 输出

  一行一个非负整数，表示方案数对998244353的模数。

  ## 样例输入

  ```
  5
  ```

  ## 样例输出

  ```
  8
  ```

  ## 提示

  ```
  对于30%的数据，n<=10
  
  对于60%的数据，n<=1000
  
  对于100%的数据，n<=10^5
  ```

  * ##### 分析：

    该题是求小顶堆的数目，使用完全二叉树+dp 即可解出。

    $dp[i]=dp[2*i]*dp[2*i+1]*c_{i-1}^{s[left]}$ 

  ```c++
  #include <iostream>
  using namespace std;
  #define ll long long
  #define MAXN 100010
  const int P=998244353;
  ll dp[MAXN*2],s[MAXN*2],a[MAXN];
  
  
  //完全二叉树+dp
  // dp[i]=dp[2*i] * dp[2*i+1] * c (i-1,left)
  
  ll cal(ll a,ll b)
  {
      if(b==1)
          return a;
  
      ll ret =cal(a*a%P,b/2);
      if(b%2)
          ret=ret*a%P;
      return ret;
  }
  ll c(ll n,ll m)
  {
      ll ret=a[n];
      ret=ret*cal(a[m],P-2)%P;
      ret=ret*cal(a[n-m],P-2)%P;
      return ret;
  }
  ll Lucas(ll n,ll m)
  {
      return c(n/P,m/P)*c(n%P,m%P)%P;
  }
  
  int main()
  {
      int i,n;
      a[0]=1;
      for(i=1;i<MAXN;++i)
          a[i]=a[i-1]*i%P;
  
      for(i=0;i<2*MAXN;++i)
          dp[i]=1;
  
      cin>>n;
  
      //计算节点i及其子树的节点数
      for(i=n;i>0;--i)
      {
          s[i]++;
          s[i/2]+=s[i];
      }
  
      for(i=n;i>0;--i)
      {
          dp[i]=dp[2*i]*dp[2*i+1]%P * Lucas(s[i]-1,s[2*i]) %P;
      }
  
      cout<<dp[1]<<endl;
  
      return 0;
  }
  ```

  

