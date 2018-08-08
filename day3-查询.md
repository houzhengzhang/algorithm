* 查找X

  ## 题目描述

  已知n个整数a[0],a[1],…,a[n-1]。有m次询问，每次询问输入一个整数x，求x是否存在于a[0],a[1],…,a[n-1]当中。如果存在输出1，否则输出0。

  ## 输入

  第一行包含两个整数n和m。

  第二行包含n个整数。

  第三行包含m个整数

  ## 输出

  输出m行，每行包含一个整数。

  ## 样例输入

  ```
  5 3
  3 6 8 3 1
  1 4 3
  ```

  ## 样例输出

  ```
  1
  0
  1
  ```

  ## 提示

  ```
  对于40%的数据，n,m<=1000。
  
  对于100%的数据，n,m<=100000,0<=a[i],x<=1000000000。
  ```

  * 解法1：使用vector构造哈希散列

    ```
    #include <iostream>
    #include<cstdio>
    #include<vector>
    using namespace std;
    #define MAXN 10001
    const int M = 10000;
    vector<int> v[MAXN];
    vector<int>::iterator it;
    
    int main()
    {
        int n, m, a, b, i;
        scanf("%d%d", &n, &m);
    
        while(n--)
        {
            scanf("%d ", &a);
            v[a%M].push_back(a);
        }
        while(m--)
        {
            scanf("%d", &b);
            if (!v[b%M].size())
            {
                printf("0\n");
                continue;
            }
            for (it = v[b%M].begin(); it != v[b%M].end(); ++it)
                if (*it == b)
                {
                    printf("1\n");
                    break;
                }
            if (it == v[b%M].end())
                printf("0\n");
        }
    }
    ```

    

   