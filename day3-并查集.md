* 家谱 - 1199

  ## 题目描述

   现代的人对于本家族血统越来越感兴趣，现在给出充足的父子关系，请你编写程序找到某个人的最早的祖先。

  ## 输入

  多行组成，首先是一系列有关父子关系的描述，其中每一组父子关系由二行组成，用#name的形式描写一组父子关系中的父亲的名字，用+name的形式描写一组父子关系中的儿子的名字；接下来用?name的形式表示要求该人的最早的祖先；最后用单独的一个$表示文件结束。规定每个人的名字都有且只有6个字符，而且首字母大写，且没有任意两个人的名字相同。最多可能有1000组父子关系，总人数最多可能达到50000人，家谱中的记载不超过30代。

  ## 输出

  求出每一个要找祖先的人的祖先，格式：本人的名字+一个空格+祖先的名字+回车。

  ## 样例输入

  ```
  #George
  +Rodney
  #Arthur
  +Gareth
  +Walter
  #Gareth
  +Edward
  ?Edward
  ?Walter
  ?Rodney
  ?Arthur
  $
  ```

  ## 样例输出

  ```
  Edward Arthur
  Walter Arthur
  Rodney George
  Arthur Arthur
  ```

  * ##### 分析：

    该题为并查集的变形

  * 代码

    ```
    #include <iostream>
    #include<cstdio>
    #include<map>
    #include <string>
    using namespace std;
    
    map<string,string>mp;
    
    string find(string a)
    {
        return a==mp[a]?a:find(mp[a]);
    }
    char op;
    string b,c;
    
    int main()
    {
        while(1)
        {
            cin>>op;
            if(op=='$')
                return 0;
            if(op=='#')
            {
                cin>>b;
                if(!mp.count(b))
                    mp[b]=b;
            }
            else if(op=='+')
            {
                cin>>c;
                b=find(b);
                mp[c]=b;
            }
            else if(op=='?')
            {
                cin>>c;
                b=find(c);
                cout<<c<<" "<<b<<endl;
            }
    
        }
        return 0;
    }
    ```

    

