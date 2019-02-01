* 有重复元素的排列问题

  ## 题目描述

  设R={ r1, r2, ……, rn }是要进行排列的n个元素。其中元素r1 ,r2 ,……,rn可能相同。试设计一个算法，列出R的所有不同排列。
  给定n以及待排列的n个元素。计算出这n个元素的所有不同排列。

  ## 输入

  输入数据的的第1行是元素个数n，1≤n≤500。接下来的1行是待排列的n个元素。

  ## 输出

  将计算出的n个元素的所有不同排列输出，每种排列占1行，最后1行中的数是排列总数。

  ## 样例输入

  ```
  4
  aacc
  ```

  ## 样例输出

  ```
  aacc
  acac
  acca
  caac
  caca
  ccaa
  6
  ```

  **记录：**

  ​	使用next_permutation（）前需要先排序，该题使用cin，cout会时间超限。

  ```
  #include<iostream>
  #include<cstdio>
  #include<cstring>
  #include<algorithm>
  using namespace std;
  char ch[510];
  int n,cnt=0,i;
  
  int main()
  {
      memset(ch,'\0',sizeof(ch));
      scanf("%d",&n);
      scanf("%s",&ch) ;
      sort(ch,ch+n);
      do
      {
          for(i=0; i<n; ++i)
              printf("%c",ch[i]);
  
          printf("\n");
          cnt+=1;
      }
      while(next_permutation(ch,ch+n));
  
      printf("%d",cnt);
  }
  ```

* 自然数的拆分

  ## 题目描述

  **任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。**

  ## 输入

  一个整数n

  ## 输出

  多行，拆分方案，按字典序输出。

  ## 样例输入

  ```
  7
  ```

  ## 样例输出

  ```
  1+1+1+1+1+1+1
  1+1+1+1+1+2
  1+1+1+1+3
  1+1+1+2+2
  1+1+1+4
  1+1+2+3
  1+1+5
  1+2+2+2
  1+2+4
  1+3+3
  1+6
  2+2+3
  2+5
  3+4
  ```

  ```c++
  #include<iostream>
  #include<cstdio>
  int a[11111]= {1};
  int n;
  
  void print(int t)
  {
      int i;
      for(i=1;i<=t-1;++i)
          printf("%d+",a[i]);
      printf("%d\n",a[i]);
  }
  
  void dfs(int m,int t)
  {
      int i;
      for(i=a[t-1];i<=m;++i)
      {
          if(i<n){
              a[t]=i;
              m-=i;
              if(m==0)
                  print(t);
              else
                  dfs(m,t+1);
              m+=i;
          }
      }
  }
  
  int main()
  {
      scanf("%d",&n);
      dfs(n,1);
      return 0;
  }
  ```

  