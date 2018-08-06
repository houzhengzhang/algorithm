* 矩阵快速幂 1919

  ```
  题目描述
  求斐波那契数列的第n项。
  由于答案太大，所以请输出模m的答案。
  输入
  一行两个整数，分别表示n,m。
  输出
  一行一个整数，输出f_n mod m。
  样例输入
  5 10
  样例输出
  8
  ```

  ```c++
  #include <iostream>
  using namespace std;
  const int N =2;
  struct Matrix
  {
      long long mat[N][N];
      Matrix()
      {
          for(int i=0; i<N; ++i)
              for(int j=0; j<N; ++j)
                  mat[i][j]=0;
      };
  };
  
  Matrix m,ans;
  Matrix Mul(Matrix A,Matrix B,long long c)
  {
      int i,j,k;
      Matrix temp;
      for(i=0; i<N; ++i)
          for(j=0; j<N; ++j)
          {
              for(k=0; k<N; ++k)
              {
                  temp.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
              }
              temp.mat[i][j]%=c;
          }
      return temp;
  }
  
  int main()
  {
  
      int f1=1,f2=1;
      int a,b,n;
      for(int i=0; i<N; ++i)
          for(int j=0; j<N; ++j)
              if(i==j)
                  ans.mat[i][j]=1;
              else
                  ans.mat[i][j]=0;
      cin>>a>>b>>n;
  
      m.mat[0][0]=0;
      m.mat[0][1]=b;
      m.mat[1][0]=1;
      m.mat[1][1]=a;
      n-=1;
      while(n)
      {
          if(n%2)
              ans= Mul(ans,m,7);
          m=Mul(m,m,7);
          n/=2;
  
      }
  
      long long res = f1*ans.mat[0][0]+f2*ans.mat[1][0];
  
      cout<<res%7<<endl;
  
      return 0;
  }
  ```

  