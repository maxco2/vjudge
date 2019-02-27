#include<bits/stdc++.h>
using  namespace  std;

void  solve();
int  n,p,q;
int  nump[250*250];
int  numq[250*250];
int  main()
{
    ios::sync_with_stdio(false);
    int  t;
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>q;
        for(int  i=0;i<=p;++i) cin>>nump[i];
        for(int  i=0;i<=q;++i) cin>>numq[i];
        solve();
    }
}
//int  dp[2][250*250];
//void  solve()
//{
    //memset(dp,0,sizeof(dp));
    //int  now=0,pre=1;
    //for(int  i=0;i<=p;++i)
    //{
        //for(int j=0;j<=q;++j)
        //{
            //if(nump[i]==numq[j])
                //dp[now][j+1]=dp[pre][j]+1;
            //else
                //dp[now][j+1]=max(dp[pre][j+1],dp[now][j]);
        //}
        //swap(pre,now);
    //}
    //cout<<dp[pre][q+1]<<endl;
//}
#define  MAXN2  250*250
int  mem[MAXN2+1];
int  dp[MAXN2];
void solve(int* n1,int  sz1,int *n2,int sz2)
{
    static  int  test=1;
    memset(mem,-1,sizeof(mem));
    fill(dp,dp+sz1,MAXN2+1);
    for(int i=0;i<sz2;++i)
        mem[n2[i]]=i;
    for(int i=0;i<sz1;++i)
    {
        if(mem[n1[i]]!=-1)
            *lower_bound(dp,dp+sz1,mem[n1[i]])=mem[n1[i]];
    }
    cout<<"Case "<<test++<<": "<<lower_bound(dp,dp+sz1,MAXN2+1)-dp<<endl;
}
void  solve()
{
    if(p<q)  solve(nump,p+1,numq,q+1);
    else
    solve(numq,q+1,nump,p+1);
}
