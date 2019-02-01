* 线性筛法 

  * 用途：在O(n)的时间内筛出[1,n]范围内所有的素数 

  * 方法如下： 枚举 $ i=2..n$ ，如果 $i$ 没有被标记为“不是素数”就把 $i$ 加入数组，无论 $i$ 是不是素数，枚举已经筛到的每一个素数p，将 $i*p $ 标记为“不是素数” ；如果 $i$ 是 $p $ 的倍数，退出循环， 这样可以保证一个数只会被最小素因子筛到一次，因此复杂度为O(n)

  * 代码

    ```c++
    #include<cstdio> 
    using namespace std;
    const int P=1000000;
    int a[P];
    int main()
    {
        int n,num=0,i,j;
        scanf("%d",&n);
    
        for(i=2;i<n;++i)
        {
            if(!a[i]) a[num++]=i;
            for(j=2;j*i<n;++j)
            {
                a[i*j]=1;
                // 保证一个数只会被最小素因子筛到一次
                //eg 3*5=5*3=15
                // 如果没有判断 15 会被筛到两次
                if(i%j==0) break;
            }
        }
        for(i=0;i<num;++i)
            printf("%d\n",a[i]);
    
    	return 0;
    }
    ```

    