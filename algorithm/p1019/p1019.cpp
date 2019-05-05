// Source : https://www.luogu.org/problemnew/show/P1019
// Date   : 2019-04-15
/**
    dfs 单词接龙

根据题意：
    一个单词最多用两次，单词可以不全用完，不可以包含：按照贪心原则，重叠部分应该越少越好


*/

#include<iostream>
#include<string>
using namespace std;
#define N 21

string str[N];
int use[N],n,length;

// 计算两个串的最短重叠长度
int interLength(string str1, string str2){
    for(int i=1; i<min(str1.length(), str2.length());++i){
        int flag =1;
        for(int j=0;j<i;++j)
            if(str1[str1.length()-i+j]!=str2[j]) flag=0;
        if(flag)
            return i;
    }
    // 无重叠部分
    return 0;
}


void dfs(string str_cur, int length_cur)
{
    length = max(length, length_cur);
    for(int i=0;i<n;++i){
        // 最多使用两次
        if(use[i]>=2)   continue;
        // 求两个字符串重叠的长度
        int len = interLength(str_cur, str[i]);
        // 有重叠部分
        if(len>0){
            use[i]++;
            dfs(str[i], length_cur + str[i].length() - len);
            // 清除记录，回溯
            use[i]--;
        }

    }

}

int main()
{
    cin>>n;
    // str[n]为开始字符
    for(int i=0;i<=n;++i)
        cin>>str[i];
    // 为了指定第一个字符，而且因为interLength需要重叠部分小于最短长度-1，
    // 所以要从前面添加一个无意义充长度的‘ ’。这样就强制了interLength函数比较最后一位。
    dfs(" " + str[n],1);
    cout<<length<<endl; 
    return 0;
}

