#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int n,t;
struct Ival
{
    int st;
    int ed;
    Ival():st(0),ed(0){};
    bool operator<(const Ival& that)const
    {
        if(st==that.st)
        {
            return  ed>that.ed;
        }
        return st<that.st;
    }
};
Ival ival[25000];
void    solve();
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i)
        scanf("%d%d",&ival[i].st,&ival[i].ed);
    sort(ival,ival+n);
    solve();
}
void solve()
{
    int cl=1,cr=0,i=0;
    int res=0;
    bool c=true;
    while(cr<t&&c)
    {
        c=false;
    for(;i<n;++i)
    {
        if(ival[i].st<=cl)
        {
            c=true;
            cr=max(cr,ival[i].ed);
        }
        else
            break;
    }
    if(c)
        cl=cr+1,res++;
    else
        break;
    }
    printf("%d\n",cr>=t?res:-1);
}
