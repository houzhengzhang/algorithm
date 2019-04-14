// Source : https://www.luogu.org/problemnew/show/P1181
// Date   : 2019-04-013
/**
边读入边判断即可
*/

#include <iostream>
using namespace std;
int n,m,x,k=0,ans=0;

int main()
{
    cin>>n>>m;
    while(n--){
        cin>>x;
        if(k+x<=m){
            k+=x;
        }else{
            ++ans;
            k=x;
        }

    }
    cout <<ans+1<< endl;
}

