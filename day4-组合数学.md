* 字符排列问题

  ## 题目描述

  有n个字母，列出由该字母组成的字符串的全排列（相同的排列只计一次）。

  ## 输入

  第一行输入是字母个数n，1<=n<=20。接下来一行输入的是待排列的n个字母。

  ## 输出

  计算出的n 个字母的所有不同排列总数

  ## 样例输入

  ```
  4
  aacc
  ```

  ## 样例输出

  ```
  6
  ```

  * ##### 分析：

    该题属于有重复元素的排列问题，通过穷举计数会超时，所以要使用排列组合相关知识来做，可以对重复字母进行计数，然后用 $A_n^n$ 除以每个字母的排列数即可。

  ```c++
  #include <iostream>
  #include<cstdio>
  #include<cstring>
  using namespace std;
  #define ll long long
  #define MAXN 25
  ll a[MAXN];
  ll ans=0;
  char ch[25];
  
  int main()
  {
  
      int letter[52]= {0};
      ll n,m,i;
      a[0]=1;
      for(i=1; i<MAXN; ++i)
          a[i]=a[i-1]*i;
  
      cin>>n>>ch;
  
      for(i=0; i<n; ++i)
          letter[ch[i]-'A']+=1;
  
      ans=a[n];
  
      for(i=0; i<52; ++i)
      {
          if(letter[i])
          {
              ans/=a[letter[i]];
          }
      }
  
      cout<<ans<<endl;
      return 0;
  }
  ```

  

