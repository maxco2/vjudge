#include <bits/stdc++.h>
using  namespace  std;
string  a,b;
//dp[i+1,j+1]=max(dp[i][j]+1,dp[i+1][j],dp[i][j+1]) si+1=sj+1
//=max(dp[i][j+1],dp[i+1][j] 
int  dp[2][1000];
void  solve()
{
    memset(dp,0,sizeof(dp));
    int  sz1=a.size();
    int  sz2=b.size();
    int  now=0,pre=1;
    for(int  i=0;i<sz1;++i)
    {
        for(int  j=0;j<sz2;++j)
        {
            if(a[i]==b[j])
            {
                dp[now][j+1]=dp[pre][j]+1;
            }
            else
            {
                dp[now][j+1]=max(dp[pre][j+1],dp[now][j]);
            }
        }
            swap(now,pre);
    }
    cout<<dp[pre][sz2]<<endl;
}
int  main()
{
    ios::sync_with_stdio(false);
    while(cin>>a>>b)
    {
        solve();
    }
}
