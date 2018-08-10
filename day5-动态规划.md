*  最长公共子序列

  #### 题目描述

  一个给定序列的子序列是在该序列中删去若干元素后得到的序列。确切地说，若给定序列*X*=<*x*1, *x*2,…, *x*m>，则另一序列*Z*=<*z*1, *z*2,…, *z*k>是*X*的子序列是指存在一个严格递增的下标序列 <*i*1, *i*2,…, *i*k>，使得对于所有*j*=1,2,…,k有

  xij=  zj

  给定两个序列X=<*x*1, *x*2, …, *x*m>和Y=<*y*1, *y*2, … , *y*n>，要求找出X和Y的一个最长公共子序列。

  例如，序列*Z*=<B,C,D,B>是序列*X*=<A,B,C,B,D,A,B>的子序列，相应的递增下标序列为<2,3,5,7>。给定两个序列*X*和*Y*，当另一序列Z既是X的子序列又是Y的子序列时，称Z是序列X和Y的公共子序列。例如，若X=<A, B, C, B, D, A, B>和Y=<B, D, C, A, B, A>，则序列<B, C, A>是X和Y的一个公共子序列，序列<B, C, B, A>也是X和Y的一个公共子序列。而且，后者是X和Y的一个最长公共子序列，因为X和Y没有长度大于4的公共子序列。

  #### 输入

  共有两行，每行为一个由大写字母构成的长度不超过200的字符串，表示序列X和Y。

  #### 输出

  一个非负整数，表示所求得的最长公共子序列的长度。

  #### 样例输入

  ```
  ABCBDAB
  BDCABA
  ```

  #### 样例输出

  ```
  4
  ```

  * 分析：

  		 递推式： $dp[i][j]= \begin{cases} dp[i-1][j-1]+1 & if A[i]=B[i]   \\         max(dp[i-1][j],dp[i][j-1]) & if   A[i] != B[i]\end{cases} $ 	

  * 代码：

    ```c++
    #include <iostream>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    #define MAXN 210
    
    char a[MAXN],b[MAXN];
    int dp[MAXN][MAXN];
    
    int main()
    {
        int i,j,m,n;
        cin>>a>>b;
        m=strlen(a);
        n=strlen(b);
    
        for(i=0;i<=m;++i)
            for(j=0;j<=n;++j)
            {
                if(i==0||j==0) dp[i][j]=0;
                // 字符串需要从0开始
                // dp[][] 下标从0开始
                else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                // 没有公共元素的情况
                else if(a[i-1]!=b[j-1])
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        cout << dp[m][n]<< endl;
        return 0;
    }
    
    ```

* 最长单调递增子序列

  状态转移方程： 

  ```
  if(n==0) dp[n]=1;
  else dp[n]=max{dp[i]+1 (i<n&&a[i]<a[n])};
  ```

  时间复杂度：$O(n^2)$ 

  ```
  int LIS(int a[],int n)
  {
      int i,j;
      // dp[i] 表示a中以a[i]为末尾元素的最长递增子序列的长度
      int dp[1000];
      // 以a[1]为末元素的最长递增子序列长度为1
      dp[0]=1;
      for(i=1; i<n; ++i)
          dp[i]=0;
  
      for(i=1; i<n; ++i)
      { 
          for(j=0; j<i && a[j]<a[i]; ++j)
              dp[i]=max(dp[j],dp[i]);
          // 将 a[i] 加到序列末尾
          dp[i]+=1; 
      }
      // 返回最长递增子序列的长度
      return dp[n-1];
  }
  ```

  * 优化：

    * 某一长度的最长单调子序列只需要保存一个最优解，进行后续计算。

    * $d[i]$ : 长度为 $i$ 的单调子序列的末尾元素的最小值，这个序列必然是单调递增的。 

    * 加入序列元素 $a[n+1]$ 时，不用更新以前的所有状态。只需要更新比 $a[n+1]$  大的最小的dp数组值。如果不存在，就将a[n+1]插入到dp数组的末尾

    * 最后dp数组的长度就是最长单调递增子序列的长度

      **实现代码：**

      ```c++
      #include <iostream>
      using namespace std;
      const int MAXN=200001;
      int dp[MAXN],a[MAXN];
      
      int main()
      {
          int n,i,j,num=1;
          cin>>n;
          for(i=0; i<n; ++i)
              cin>>a[i];
          for(i=0; i<n; ++i)
          {
              //如果 a[i] 大于 dp 末尾的值，则将a[i] 插入到dp末尾
              if(a[i]>dp[num-1])
                  dp[num++]=a[i];
              else
              {
                  // 找到比a[i]的大的最小dp值的位置
                  for(j=0; j<num && a[i]<dp[j]; ++j);
                  // 更新dp数组的值
                  dp[j]=a[i];
              }
          }
          cout<<num-1<<endl;
          return 0;
      }
      ```

      

    * 通过二分查找，将查找比 $a[n+1]$  大的最小的dp数组值的复杂度将为 $O\big(log(n)\big)$ ，算法总复杂度为 $ O\big( n* log(n) \big)$ 

      **实现代码：**

      ```c++
      #include <iostream>
      using namespace std;
      
      const int MAXN=200001;
      int dp[MAXN],a[MAXN];
      
      int main()
      {
          int n,i,j,l,r,mid,len=0,p;
          cin>>n;
          for(i=1; i<=n; ++i)
              cin>>a[i];
          for(i=1; i<=n; ++i)
          {
              l=1;r=len;
              p=len+1;
              
              while(l<=r)
              {
                  mid=(l+r)/2;
      
                  if(a[i]>dp[mid])
                  {
                      l=mid+1;
                  }
                  else
                  {
                      r=mid-1;
                      //记录插入位置
                      p=mid;
                  }
              }
              dp[p]=a[i];
              // 插入到dp末尾 更新dp长度
              if(p==len+1) len++;
          }
          cout<<len<<endl;
          return 0;
      }
      ```

* #### 例题

  #### 题目描述

  LIS问题是最经典的动态规划基础问题之一。如果要求一个满足一定条件的最长上升子序列，你还能解决吗？

  ​       给出一个长度为N整数序列，请求出它的包含第K个元素的最长上升子序列。

  ​       例如：对于长度为6的序列<2,7,3,4,8,5>，它的最长上升子序列为<2,3,4,5>，但如果限制一定要包含第2个元素，那么满足此要求的最长上升子序列就只能是<2,7,8>了。

  #### 输入

  第一行为两个整数N,K，如上所述。

   接下来是N个整数，描述一个序列。

  #### 输出

  请输出两个整数，即包含第K个元素的最长上升子序列长度。

  #### 样例输入

  ```
  8 6
  65 158 170 299 300 155 207 389
  ```

  #### 样例输出

  ```
  4
  ```

  #### 提示

  ```
  80%的数据，满足0<n<=1000，0<k<=n
  
  100%的数据，满足0<n<=200000，0<k<=n
  ```

  #### AC代码

  ```c++
  #include <iostream>
  using namespace std;
  
  const int MAXN=200010;
  int dp[MAXN],a[MAXN];
  
  int main()
  {
      int n,k,i,l,r,mid,len=0,p;
      cin>>n>>k;
      // 第k个数 从1 开始
      for(i=1; i<=n; ++i)
          cin>>a[i];
      for(i=1; i<=n; ++i)
      {
          // 删去a[k] 前面比 a[k] 大的数和a[k]后面比a[k]小的数，从而保证a[k]一定在所求序列中
          if(a[i]>=a[k] && i<k) continue;
          else if(a[i]<=a[k] && i>k) continue;
  
          l=1;r=len;
          // p记录待插入元素的位置
          p=len+1;
          // 二分查找比a[k]大的最小值的位置
          while(l<=r)
          {
              mid=(l+r)/2;
              if(a[i]>dp[mid])
              {
                  l=mid+1;
              }
              else
              {
                  r=mid-1;
                  p=mid;
              }
          }
          // 更新dp数组
          dp[p]=a[i];
          // 未找到则插入dp末尾，同时序列长度+1
          if(p==len+1) len++;
      }
      cout<<len<<endl;
      return 0;
  }
  ```

  





