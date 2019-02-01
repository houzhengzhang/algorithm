* 中缀表达式转后缀表达式

  ## 题目描述

  请编写程序将一个中缀表达式转换为后缀表达式。

  ## 输入

  仅一行，是一个中缀表达式。输入的符号中只有这些基本符号“0123456789+-*/()”，并且不会出现形如2*-3的格式，所有数字都是个位数，“/”表示整除运算。

  ## 输出

  仅一行，是转换后的后缀表达式。数字之间、运算符之间、数字和运算符之间都用一个空格隔开

  ## 样例输入

  ```
  8-(3+2*6)/5+4
  ```

  ## 样例输出

  ```
  8 3 2 6 * + 5 / - 4 +
  ```

  ## 提示

  表达式长度<=200

  ```
  #include<iostream>
  #include<stack>
  #include<string>
  using namespace std;
  
  char precede(char a,char b)
  {
      char table[8][8]=
      {
          {' ', '+', '-', '*', '/', '(', ')','#'},
          {'+','>', '>', '<', '<', '<', '>', '>'},
          {'-','>', '>', '<', '<', '<', '>', '>'},
          {'*','>', '>', '>', '>', '<', '>', '>'},
          {'/','>', '>', '>', '>', '<', '>', '>'},
          {'(','<', '<', '<', '<', '<', '=', '>'},
          {')','>', '>', '>', '>', ' ', '>', '>'},
          {'#','<', '<', '<', '<', '<', '<', '<'}
      };
      int i,j;
      for(i=0; i<8; ++i)
          if(table[0][i] == a)
              break;
      for(j=0; j<8; ++j)
          if(table[j][0] == b)
              break;
      return table[j][i];
  }
  int main()
  {
      string str;
      stack<char> st;
      st.push('#');
      cin>>str;
      str+='#';
      int i=0,num=0;
      string res;
      while(str[i]!='#')
      {
          if(str[i]>='0' && str[i]<='9')
          {
              res+=str[i];
          }
          else if(str[i]=='(')
              st.push(str[i]);
          else if(str[i]==')')
          {
              while(st.top()!='(')
              {
                  res+=st.top();
                  st.pop();
              }
              st.pop();
          }
          else
          {
              while(precede(str[i],st.top()) =='>' )
              {
                  res+=st.top();
                  st.pop();
              }
              st.push(str[i]);
          }
          i++;
      }
      while(st.top()!='#')
      {
          res+=st.top();
          st.pop();
      }
      for(i=0;i<res.size();++i)
      {
          if(i==0)
              cout<<res[i];
          else
              cout<<" "<<res[i];
      }
  
  }
  
  ```

  