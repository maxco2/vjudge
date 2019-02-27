#include<bits/stdc++.h>
using  namespace  std;
int  sig[40001];
void  solve();
int  p;
int  main()
{
    ios::sync_with_stdio(false);
    int  t;
    cin>>t;
    while(t--)
    {
        cin>>p;
        for(int i=1;i<=p;++i)
        {
            cin>>sig[i];
        }
        solve();
    }
}
int  dp[40001];
//dp[i]=max(1,dp[j]+1)  j<i&&aj<ai
//void  solve()
//{
    //for(int i=1;i<=p;++i)
    //{
        //dp[i]=1;
        //for(int j=1;j<i;++j)
            //if(sig[j]<sig[i])
                //dp[i]=max(dp[i],dp[j]+1);
    //}
    //cout<<*max_element(dp+1,dp+p+1)<<endl;
//}


void  solve()
{
    fill(dp,dp+p,50000);
    for(int i=1;i<=p;++i)
        *lower_bound(dp,dp+p,sig[i])=sig[i];
    //for(int  i=0;i<=p;++i)
        //cout<<"dp["<<i<<"]="<<dp[i]<<" ";
    //cout<<endl;
    cout<<lower_bound(dp,dp+p,50000)-dp<<endl;
}
