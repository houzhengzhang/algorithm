* 月度开销---整型

  ## 题目描述

  农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。他计算出并记录下了接下来 N (1 ≤ N ≤ 100,000) 天里每天需要的开销。

  约翰打算为连续的M (1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。

  约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。

  ## 输入

  第一行包含两个整数N,M，用单个空格隔开。
  接下来N行，每行包含一个正整数，按顺序给出接下来N天里每天的开销。

  ## 输出

  一个整数，即最大月度开销的最小值。

  ## 样例输入

  ```
  7 5
  100
  400
  300
  100
  500
  101
  400
  ```

  ## 样例输出

  ```
  500
  ```

* 代码

  ```c++
  #include <iostream>
  using namespace std;
  #define ll long long
  ll pay[100010];
  ll fajo=0;
  ll count=0;
  int main()
  {
      ll l=0,mid=0,r=0;
      ll n,m,i;
      cin>>n>>m;
      for(i=0; i<n; ++i)
      {
          cin>>pay[i];
          r+=pay[i];              //sum
          //****************************************/
          if(pay[i]>l) l=pay[i];  // max
          //*****************************************/
      }
      while(l<r)
      {
          mid = l+(r-l)/2;
          fajo=0;
          count=0;
  
          for(i=0; i<n; ++i)
          {
              if(fajo+pay[i]>mid)
              {
                  fajo=pay[i];
                  count+=1;
              }
              else  fajo+=pay[i];
          }
  
          if(count<m)
          {
              r=mid;
          }
          else
          {
              l=mid+1;
          }
          cout<<"mid:"<<mid<<endl;
      }
      cout<<l<<endl;
  
      return 0;
  }
  ```

  #### 未AC

  ```c++
  #include <iostream>
  using namespace std;
  #define ll long long
  
  ll pay[10001];
  ll fajo=0;
  ll count=0;
  
  
  int main()
  {
      ll l=0,mid=0,r=0;
      int n,m,i;
      cin>>n>>m;
      for(i=0; i<n; ++i)
      {
          cin>>pay[i];
          r+=pay[i];
          if(pay[i]>=l) l=pay[i];
      }
      while(l<=r)
      {
          mid = (l+r)/2;
          fajo=0;
          count=0;
          for(i=0; i<n; ++i)
          {
              if(fajo+pay[i]<=mid)
                  fajo+=pay[i];
              else
              {
                  fajo=pay[i];
                  count+=1;
              }
          }
  
          if(count<m)
          {
              r=mid-1;
          }
          else
          {
              l=mid+1;
          }
      }
      cout<<mid<<endl;
      return 0;
  }
  
  ```

* 网线主管

  ## 题目描述

  仙境的居民们决定举办一场程序设计区域赛。裁判委员会完全由自愿组成，他们承诺要组织一次史上最公正的比赛。他们决定将选手的电脑用星形拓扑结构连接在一起，即将它们全部连到一个单一的中心服务器。为了组织这个完全公正的比赛，裁判委员会主席提出要将所有选手的电脑等距离地围绕在服务器周围放置。

  为购买网线，裁判委员会联系了当地的一个网络解决方案提供商，要求能够提供一定数量的等长网线。裁判委员会希望网线越长越好，这样选手们之间的距离可以尽可能远一些。

  该公司的网线主管承接了这个任务。他知道库存中每条网线的长度（精确到厘米），并且只要告诉他所需的网线长度（精确到厘米），他都能够完成对网线的切割工作。但是，这次，所需的网线长度并不知道，这让网线主管不知所措。

  你需要编写一个程序，帮助网线主管确定一个最长的网线长度，并且按此长度对库存中的网线进行切割，能够得到指定数量的网线。

  ## 输入

  第一行包含两个整数N和K，以单个空格隔开。N（1 <= N <= 10000）是库存中的网线数，K（1 <= K <= 10000）是需要的网线数量。
  接下来N行，每行一个数，为库存中每条网线的长度（单位：米）。所有网线的长度至少1m，至多100km。输入中的所有长度都精确到厘米，即保留到小数点后两位。

  ## 输出

  网线主管能够从库存的网线中切出指定数量的网线的最长长度（单位：米）。必须精确到厘米，即保留到小数点后两位。
  若无法得到长度至少为1cm的指定数量的网线，则必须输出“0.00”（不包含引号）。

  ## 样例输入

  ```
  4 11
  8.02
  7.43
  4.57
  5.39
  ```

  ## 样例输出

  ```
  2.00
  ```

* 代码

  ```c++
  #include <iostream>
  #include<iomanip>
  using namespace std;
  #define ll long long
  ll line[10005];
  int main()
  {
      ll l=0,mid=0,r=0,sum=0;
      ll n,k,i;
      double x;
      cin>>n>>k;
      for(i=0; i<n; ++i)
      {
          cin>>x;
          line[i]=int(x*100+0.5);
          if(line[i]>r) r=line[i];
          sum+=line[i];
      }
      //右端点为网线总长/需要数量
      //左端点>=最长网线/需要数量。
      l=r/k;
      r=sum/k;
   
      ll cnt=0;
  
      while(l<r)
      {
          cnt=0;
          mid = (l+r+1)/2;
          for(int i=0;i<n;++i)
          {
              cnt+=int(line[i]/mid);
          }
          if(cnt < k){
              r=mid-1;
          }else{
              l=mid;
          }
      }
      if(l>=1)
          cout<<fixed<<setprecision(2)<<l/100.0<<endl;
      else cout<<"0.00"<<endl;
      return 0;
  }
  
  
  ```

  

```c++
#include<iomanip>
#include<iostream>
using namespace std;
double x;
long long y,z,l,r,mid,s[10005],n,m,w;
int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        cin>>x;
        s[i]=int(x*100+0.5);
        z=z>s[i]? z:s[i];
        y+=s[i];
    }
    l=z/n,r=y/n;
    while(l<r)
    {
        w=0,mid=(l+r+1)/2;
        for(int i=1; i<=m; i++)
            w+=int(s[i]/mid);
        if(w>=n) l=mid;
        else r=mid-1;
    }
    if(l>=1)
        cout<<fixed<<setprecision(2)<<l/100.0<<endl;
    else cout<<"0.00"<<endl;
}
```



