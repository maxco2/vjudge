#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include<vector>
using namespace std;
int num1[505];
int num2[505];
int n1, n2;
int table[505];//store ending of num2[j] LCIS length
int parent[505];
#define  MEMSET(x,v)  memset(x,v,sizeof(x))
//dp[j]=curlen+1 curlen+1>table[j]  num1[i]==num2[j]
//update curlen          num1[i]>num2[j]
int prevv[501][501];
void solve()
{
    MEMSET(table,0);
    MEMSET(parent,0);
    MEMSET(prevv,-1);
    for(int i=0;i<n1;++i)
    {
        int curlen=0,last=-1;
        for(int j=0;j<n2;++j)
        {
            if(num1[i]==num2[j]&&curlen+1>table[j])
                table[j]=curlen+1,prevv[i][j]=last;
            if(num1[i]>num2[j]&&table[j]>curlen)
                curlen=table[j],last=j;
        }
    }
    int* res=max_element(table,table+n2);
    cout<<*res<<endl;
    if(*res)
    {
        int idx=res-table;
        int len=*res;
        int lcis[len];
        for (int i=n1-1, j=idx, k=len; k>0; --i)
            if (prevv[i][j] != -1)
            {
                lcis[--k] = num2[j];
                j = prevv[i][j];
            }
        for (int i=0; i<len-1; ++i)
            cout << lcis[i]<<" ";
        cout<<lcis[len-1];
    }
    cout<<endl;
}
int main()
{
    cin >> n1;
    for (int i = 0; i < n1; ++i)
        cin >> num1[i];
    cin >> n2;
    for (int i = 0; i < n2; ++i)
        cin >> num2[i];
    solve();
}
