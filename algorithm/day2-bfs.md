* 最短路径

  ## 题目描述

   在一个n*n的棋盘上从一个地方走到另一个地方，只允许马的走法。问最少走多少步可以从起点走到终点。棋盘最大是2000*2000。

   ![img](http://122.139.62.222:88/upload/201308/134.jpg)

  ## 输入

  一行，5个整数n,x1,y1,x2,y2,棋盘的大小，起点与终点的坐标,0=<x1,y1,x2,y2<n

  ## 输出

  一行，一个整数，从起点到终点最少的步数

  ## 样例输入

  ```
  8 0 0 7 0
  ```

  ## 样例输出

  ```
  5
  ```

  **记录：**

  ​	在使用bfs搜索时需要增加一个记录数组，标记已经搜索过的区域。

  ```
  #include<iostream>
  #include<cstdio>
  #include<queue>
  #include<cstring>
  using namespace std;
  #define MAX_INT ((unsigned)(-1)>>1)
  struct locate
  {
      int x,y;
      int step;
      locate(int x1=0,int y1=0,int s=0)
      {
          x=x1;
          y=y1;
          step=s;
      }
  };
  
  int fx[]= {1, 2, 2, 1, -1, -2, -2, -1};
  int fy[]= {2, 1, -1,-2,-2, -1,  1, 2};
  
  int ans=MAX_INT;
  int mp[2002][2002];
  
  int main()
  {
      queue<locate> q;
      int n,x1,x2,y1,y2;
      int tmpX,tmpY;
      int i,j;
      memset(mp,0,sizeof(mp));
  
      cin>>n>>x1>>y1>>x2>>y2;
      mp[x1][y1]=1;
  	// 坑 写成x1,x2
      q.push(locate(x1,y1,0));
  
      while(!q.empty())
      {
          locate record=q.front();
          q.pop();
          if(record.x==x2 && record.y==y2)
          {
              if(record.step<ans)
                  ans=record.step;
          }
          else
          {
              for(i=0; i<8; ++i)
              {
                  tmpX=record.x+fx[i];
                  tmpY=record.y+fy[i];
                  if(tmpX>=0 && tmpX<n && tmpY>=0 && tmpY<n && !mp[tmpX][tmpY])
                  {
                      mp[tmpX][tmpY]=1;
                      q.push(locate(tmpX,tmpY,record.step+1));
                  }
              }
          }
      }
      cout<<ans<<endl;
      return 0;
  }
  
  ```

* 海战

  ## 题目描述

  在峰会期间，武装部队得处于高度戒备。警察将监视每一条大街，军队将保卫建筑物，领空将布满了F-2003飞机。此外，巡洋船只和舰队将被派去保护海岸线。不幸的是因为种种原因，国防海军部仅有很少的几位军官能指挥大型海战。因此，他们考虑培养一些新的海军指挥官，他们选择了“海战”游戏来帮助学习。

  在这个著名的游戏中，在一个方形的盘上放置了固定数量和形状的船只，每只船却不能碰到其它的船。在这个题中，我们仅考虑船是方形的，所有的船只都是由图形组成的方形。编写程序求出该棋盘上放置的船只的总数。

  ## 输入

  头一行由用空格隔开的两个整数R和C组成，1<=R,C<=1000，这两个数分别表示游戏棋盘的行数和列数。接下来的R行每行包含C个字符，每个字符可以为“#”，也可为“.”，“#”表示船只的一部分，“.”表示水。

  ## 输出

  为每一个段落输出一行解。如果船的位置放得正确（即棋盘上只存在相互之间不能接触的方形，如果两个“#”号上下相邻或左右相邻却分属两艘不同的船只，则称这两艘船相互接触了）。就输出一段话“There are S ships.”,S表示船只的数量。否则输出“Bad placement.”。

  ## 样例输入

  ```
  6 8
  .....#.#
  ##.....#
  ##.....#
  .......#
  #......#
  #..#...#
  ```

  ## 样例输出

  ```
  There are 5 ships.
  ```

  **记录**：

  ​	该题不能直接使用bfs搜索连通块，还需要判断每个连通区域是否为矩形，如果出现三角区域，则说明船的位置放置不正确；

  ```
  #include <iostream>
  #include <cstring>
  #include<cstdio>
  #include <queue>
  #include<algorithm>
  using namespace std;
  struct point
  {
      int x;
      int y;
      point(int x1=0,int y1=0)
      {
          x=x1;
          y=y1;
      }
  };
  
  const int maxn=1100;
  int vi[maxn][maxn];
  char mp[maxn][maxn];
  int m,n;
  int nex[4][2]= {{0,-1},{0,1},{-1,0},{1,0}};
  
  int bfs(int x1,int y1)
  {
      queue<point> Q;
      int nx,ny;
      point start(0,0);
      start.x=x1;
      start.y=y1;
  
      // seed so num=1
      int num=1,tx1=x1,tx2=x1,ty1=y1,ty2=y1;
  
      Q.push(start);
      vi[x1][y1]=1;
  
      while(!Q.empty())
      {
          point temp=Q.front();
          Q.pop();
  
          for(int i=0; i<4; ++i)
          {
              nx=temp.x+nex[i][0];
              ny=temp.y+nex[i][1];
              if(nx>=0 && nx<m && ny>=0 && ny<n && !vi[nx][ny] && mp[nx][ny] =='#')
              {
                  vi[nx][ny]=1;
                  Q.push(point(nx,ny));
  
                  tx1=min(tx1,nx);
                  ty1=min(ty1,ny);
  
                  tx2=max(tx2,nx);
                  ty2=max(ty2,ny);
  
                  num++;
              }
          }
      }
  
      if((tx2-tx1+1)*(ty2-ty1+1) == num )
          return 1;
      else return 0;
  }
  
  int main()
  {
      int i,j,ans=0;
      memset(vi,0,sizeof(vi));
      memset(mp,'\0',sizeof(mp));
      cin>>m>>n;
      for(i=0; i<m; i++)
      {
          for(j=0; j<n; j++)
          {
              cin>>mp[i][j];
          }
      }
  
      for(i=0; i<m; i++)
      {
          for(j=0; j<n; j++)
          {
              if(mp[i][j]=='#' && !vi[i][j])
              {
                  if(!bfs(i,j))
                  {
                      printf("Bad placement.\n");
                      return 0;
                  }
                  ans++;
              }
          }
      }
      printf("There are %d ships.\n",ans);
      return 0;
  }
  ```

* 奇怪的楼梯

  ## 题目描述

  大楼的每一层楼都可以停电梯，而且第i层楼(1 <= i <= N)上有一个数字Ki(0 <= Ki <= N)。电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。例如：3 3 1 2 5代表了Ki(K1=3,K2=3,……)，从一楼开始。在一楼，按“上”可以到4楼，按“下”是不起作用的，因为没有-2楼。那么，从A楼到B楼至少要按几次按钮呢？

  ## 输入

  共有二行，第一行为三个用空格隔开的正整数，表示N,A,B(1≤N≤200, 1≤A,B≤N)，第二行为N个用空格隔开的正整数，表示Ki。

  ## 输出

  一行，即最少按键次数,若无法到达，则输出-1。

  ## 样例输入

  ```
  5 1 5
  3 3 1 2 5
  ```

  ## 样例输出

  ```
  3
  ```

  ```c++
  #include<iostream> 
  #include<cstring>
  using namespace std;
  int q[10001],head=0,tail=0;
  int z[300];
  int ans[10001];
  
  int main()
  {
  	int n,a,b;
  	cin>>n>>a>>b;
  	int i,x,y;
  	for(i=1;i<=n;++i)
  	{
  		cin>>z[i];
  	}
  	memset(ans,-1,sizeof(ans)); 
  
  
  	ans[a]=0;
  	head=tail=0;
  	q[tail++]=a;
  
  	while(ans[b]==-1 && head!=tail)
  	{
  		x=q[head++]; 
  		for(i=-1;i<=1;i+=2)
  		{
  			y=x+i*z[x]; 
  			if(y>=1&&y<=n && ans[y]==-1)
  			{
  				ans[y]=ans[x]+1;
  				q[tail++]=y;
  			}
  		}
  	} 
  	cout<<ans[b]<<endl;
  }
  ```

  