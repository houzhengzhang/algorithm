* gcd 和lcm

  gcd$(x,y)$ 简记为 $(x,y)$ ,表示两个数的最大公约数

  lcm$(x,y)$ 简记为 $[x,y]$ ,表示两个数的最小公倍数

  设 $x=\Pi pi^{ai}$, $y=\Pi pi^{bi}$

  那么 $(x,y) = \Pi pi ^{min(ai,bi)}$, $[x,y] = \Pi pi ^{max(ai,bi)}$

  由于 $min(ai,bi)+max(ai,bi) = ai+bi$ , 故 $ (x,y)*[x,y]=x*y$

  * 求 gcd ：辗转相除法 $O(logn)$ 

  系统提供了$\_\_gcd(x,y) $  函数，可以直接计算出x,y 的最大公约数  *<algorithm>*

* 语法百题 最大公约数与最小公倍数 - 1060

  ## 题目描述

  输入两个正整数m和n，求其最大公约数和最小公倍数。

  ## 输入

  两个整数

  ## 输出

  最大公约数，最小公倍数，中间空格

  ## 样例输入

  ```
  5 7
  ```

  ## 样例输出

  ```
  1 35
  ```

  * ##### 代码

    ```c++
    #include<cstdio>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int m,n,gcd,lcm;
    
        scanf("%d%d",&m,&n);
    
        gcd=__gcd(m,n);
        lcm=m*n/gcd;
    
        printf("%d %d\n",gcd,lcm);
    
    	return 0;
    }
    ```

    

