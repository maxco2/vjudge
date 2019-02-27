#include<bits/stdc++.h>
using  namespace  std;
#define  LEN  100000
int  pri[LEN];
int  bak[LEN];
int l1,l2;
void  solve();
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int i=0;
        while(cin.get()!='\n')
            cin>>pri[i++];
        l1=i;
        i=0;
        while(cin.get()!='\n')
            cin>>bak[i++];
        l2=i;
        solve();
    }
}
int dp[2][LEN];
void solve()
{
    memset(dp,0,sizeof(dp));
    int now=0,pre=1;
    for(int i=0;i<l1;++i)
    {
        for(int j=0;j<l2;++j)
        {
            if(pri[i]==bak[j])
                dp[now][j+1]=dp[pre][j]+1;
            else
                dp[now][j+1]=max(dp[pre][j+1],dp[now][j]);
        }
        swap(now,pre);
    }
    cout<<dp[pre][l2]<<endl;
}
