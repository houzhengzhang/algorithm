* #### 分析

  * 状态：f[n]表示凸n边形的拆分方案总数

  * 由题目中的要求可知一个凸n边形的任意一条边都必然是一个三角形的一条边，边$P_1P_n​$也不例外，再根据“不在同一直线上的三点可以确定一个三角形”，只要在 $P_2,P_3,\ \dots \ ,P_{n-1}​$ 点中找一个点$P_k​$(1<k<n)，与$P_1​$、$P_n​$ 共同构成一个三角形的三个顶点，就将n边形分成了三个不相交的部分，我们分别称之为区域①、区域②、区域③，其中区域③必定是一个三角形，区域①是一个凸k边形，区域②是一个凸n-k+1边形，区域①的拆分方案总数是f[k]，区域②的拆分方案总数是f[n-k+1]，故包含△$P_1P_kP_n​$ 的n边形的拆分方案数为f[k]*f[n-k+1]种，而$P_k​$ 可以是 $P_2,P_3,\ \dots \ ,P_{n-1}​$ 中任一点，根据加法原理，得以下递推关系式：

    ![picture](https://github.com/houzhengzhang/algorithm/blob/master/algorithm/1139/picture.png)

    $f[n]=\begin{cases} 1 \ \ \ \ \ \ \ \ \  n=2 \\ \displaystyle\sum_{i=2}^{n-1} f[i]*f[n-i+1]  \ \ \ \ \ \ \ \ \ \  n>2 \end{cases}$
