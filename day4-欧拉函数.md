* **定义**：在数论中，对正整数n，欧拉函数是小于等于n的正整数中与n互质的数的数目$( \varphi(1)=1 )$ 

* **通式： **$\varphi(x) = x \displaystyle \prod_{i=1}^{n} (1-\frac{1}{p_i})$   其中 $p_1,p_2,\cdots ,p_n $ 为x的所有质因数，x是不为0的整数。

* 例题：1103

  * ## 题目描述

    对正整数n，n的欧拉函数（即φ(N)）是少于或等于n的数中与n互质的数的数目。例如φ(8)=4，因为1,3,5,7均和8互质。

    ## 输入

    一行一个整数N。

    ## 输出

    一行一个整数φ(N)

    ## 样例输入

    ```
    8
    ```

    ## 样例输出

    ```
    4
    ```

    ## 提示

     ```
    对于70%的数据，有N<=1000
    对于100%的数据，有N<=231-1
     ```

  * ##### 代码：

    ```
    #include <iostream>
    #include<cstdio>
    using namespace std;
    #define ll long long
    int main()
    {
        ll n,i,ans=0;
    
        cin>>n;
        ans=n;
        for(i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                ans=ans*(i-1)/i;
                // i的倍数
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        if(n>1)
        {
            ans=ans*(n-1)/n;
        }
        printf("%lld\n",ans);
    
    
        return 0;
    }
    ```

    

   

  

   