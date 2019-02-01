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

* 玛雅文字 - 1444

  ## 题目描述

  考古人员最近在美洲地区发现了玛雅人留下来的文字，并且他们研究出来了玛雅文字与英文的对照关系，现在给你一些玛雅文字，请将它们翻译为英文。

  ## 输入

  首先输入若干行（最多100000行），每行包含两个字符串a和b，表示玛雅单词b所对应的英文单词为a。

  接下来输入一个空行。

  接下来若干行（最多100000行），每行包含所需要翻译的一个玛雅单词c。输入只包含小写英文字母。

  ## 输出

  对于每一个玛雅单词，输出所对应的英文单词，如果该玛雅单词所对应的英文单词未知，那么输出”eh”。

  ## 样例输入

  ```
  dog ogday
  cat atcay
  pig igpay
  froot ootfray
  loops oopslay
  
  atcay
  ittenkay
  oopslay
  ```

  ## 样例输出

  ```
  cat
  eh
  loops
  ```

  * ##### 分析：

    该题如果用cin,cout会时间超限，使用scanf()输入时，主要注意对于回车的处理

  * ##### 代码：

    ```
    #include <iostream>
    #include<cstdio>
    #include<map>
    #include <string>
    using namespace std;
    char ch[100000];
    map<string,string>mp;
    map<string,string>::iterator it;
    string pattern=" ";
    string a,b;
    int pos=0;
    char c;
    
    int main()
    {
        while(1)
        {
            scanf("%c",&ch[0]);
            if(ch[0]=='\n')
                break;
            scanf("%[^\n]",&ch[1]);
    
            scanf("%c",&c);
    
            string str(ch);
            pos=str.find(pattern);
    
    
            a=str.substr(0,pos);
            b=str.substr(pos+1,str.size());
    
            mp[b]=a;
        }
    
        while(scanf("%s",ch)!=EOF)
        {
            scanf("%c",&c);
            string str(ch);
            it = mp.find(str);
            if(it!=mp.end())
                printf("%s\n",it->second.c_str());
            else
                printf("eh\n");
        }
    
    
        return 0;
    }
    ```

    