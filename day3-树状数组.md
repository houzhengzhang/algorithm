* #### 1. 单点更新，区间查询

  * 求和 1388

    ##### 题目描述

    输入一个数列A1,A2….An(1<=N<=100000)，在数列上进行M(1<=M<=100000)次操作，操作有以下两种：

    1、格式为C I X，其中C为字符“C”，I和X(1<=I<=N,|X|<=10000)都是整数，表示把把a[I]改为X

    2、格式为Q L R，其中Q为字符“Q”，L和R表示询问区间为[L,R](1<=L<=R<=N)，表示询问A[L]+…+A[R]的值。

    ##### 输入

    第一行输入N(1<=N<=100000)，表述数列的长度，接下来N行，每行一个整数(绝对值不超过10000)依次输入每个数；接下来输入一个整数M(1<=M<=100000)，表示操作数量，接下来M行，每行为C I X或者Q L R。

    ##### 输出

    对于每个Q L R 的操作输出答案。

    ##### 样例输入

    ```
    5
    1
    2
    3
    4
    5
    3
    Q 2 3
    C 3 9
    Q 1 4
    ```

    ##### 样例输出

    ```
    5
    16
    ```

    **分析：**

    ​	该题可以使用求子段和的模版，但是模版下标是从0 开始的，注意下标问题

    *模版：*

    ```c++
    //求sum{[0..n-1]}
    //维护和查询复杂度均为O(logn)
    //用于动态求子段和,数组内容保存在sum.a[]中
    //可以改成其他数据类型
    #include <string.h>
    #define lowbit(x) ((x)&((x)^((x)-1)))
    #define MAXN 10000
    typedef int elem_t;
    
    struct sum{
    	elem_t a[MAXN],c[MAXN],ret;
    	int n;
    	void init(int i){memset(a,0,sizeof(a));memset(c,0,sizeof(c));n=i;}
    	void update(int i,elem_t v){for (v-=a[i],a[i++]+=v;i<=n;c[i-1]+=v,i+=lowbit(i));}
    	elem_t query(int i){for (ret=0;i;ret+=c[i-1],i^=lowbit(i));return ret;}
    };
    ```

    

    ##### 代码

    ```
    #include <iostream>
    #include<cstdio>
    #include<queue>
    #include <string.h>
    using namespace std;
    #define lowbit(x) ((x)&((x)^((x)-1)))
    #define MAXN 100001
    typedef int elem_t;
    
    struct sum
    {
        elem_t a[MAXN],c[MAXN],ret;
        int n;
        void init(int i)
        {
            memset(a,0,sizeof(a));
            memset(c,0,sizeof(c));
            n=i;
        }
        void update(int i,elem_t v)
        {
            for (v-=a[i],a[i++]+=v; i<=n; c[i-1]+=v,i+=lowbit(i));
        }
        elem_t query(int i)
        {
            for (ret=0; i; ret+=c[i-1],i^=lowbit(i));
    
            // sum[0,i-1)
            return ret;
        }
    };
    
    int main()
    {
        sum tree;
        int n,m,a,b;
        int left,right,res;
        char op;
        int i;
        scanf("%d",&n);
        tree.init(n);
        // 模版下标是从0开始的
        for(i=0; i<n; ++i)
        {
            scanf("%d",&a);
            tree.update(i,a);
        }
        scanf("%d",&m);
    
        while(m--)
        {
            // 忽略输入的回车
            scanf(" %c %d %d",&op,&a,&b);
            if(op=='Q')
            {
                //输入下标从1开始
                // 所以 求和范围为 
                // left [0,a-1)   right [0,b)
                left=tree.query(a-1);
                right=tree.query(b);
                printf("%d\n",right-left );
            }
            else if(op=='C')
            {
                tree.update(a-1,b);
            }
        }
    }
    ```

    