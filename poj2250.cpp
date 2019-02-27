#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#define DEBUG(x) cout << #x << x << endl;
using  namespace  std;
#define  LEN  105
int  pri[LEN];
int  bak[LEN];
int l1,l2;
map<string,int>  m;
map<int,string>  rm;
void  solve();
string  tmp;
int  hashv=1;
bool getstr(int* a,int & idx)
{
    if(!(cin>>tmp))  return  false;
    if(tmp=="#") return false;
    if(m.find(tmp)!=m.end())
        a[idx++]=m[tmp];
    else
        a[idx++]=m[tmp]=hashv++;
    rm[m[tmp]]=tmp;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    while(true)
    {
        int i=0;
        if(!getstr(pri,i))  return 0;
        while(getstr(pri,i));
        l1=i;
        i=0;
        while(getstr(bak,i));
        l2=i;
        solve();
    }
}
int dp[LEN][LEN];
void solve()
{
    for(int i=0;i<l1;++i)
    {
        for(int j=0;j<l2;++j)
        {
            if(pri[i]==bak[j])
                dp[i+1][j+1]=dp[i][j]+1;
            else
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    if(dp[l1][l2]==0)  {cout<<endl;return;}
    vector<int>  v;
    while(l1>0&&l2>0)
    {
        if(pri[l1-1]==bak[l2-1])
        {
            v.push_back(pri[l1-1]);
            l1--;
            l2--;
        }
        else  if(dp[l1-1][l2]>dp[l1][l2-1])//必须先判断l1是否-1
            l1--;
        else
            l2--;
    }
    for(int st=v.size()-1;st!=0;--st)
        cout<<rm[v[st]]<<" ";
    cout<<rm[v[0]]<<endl;
}
