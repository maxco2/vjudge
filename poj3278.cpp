#include<iostream>
#include<queue>
#include<cstring>

using namespace  std;
int  s,t;
void  bfs();
int  main()
{
    ios::sync_with_stdio(false);
    cin>>s>>t;
    bfs();
}
struct  P
{
    int pos;
    int time;
    P():pos(0),time(0){}
    P(int pos):pos(pos),time(0){}
    bool  operator<(const P&that)const {return  time>that.time;}
};
bool  vis[100001];
void bfs()
{
    memset(vis,0,sizeof(vis));
    int  res=100000;
    priority_queue<P> q;
    P p(s);
    q.push(p);
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        if(p.time>res)  continue;
        if(p.pos>t)  {res=min(res,p.pos-t+p.time);continue;}
        if(p.pos==t)  {res=min(res,p.time);continue;}
        res=min(res,t-p.pos+p.time);
        vis[p.pos]=true;
        int  cpos=p.pos;
        p.pos=cpos-1;
        p.time+=1;
        if(p.pos>=0&&p.pos<=100000&&!vis[p.pos])
        q.push(p);
        p.pos=cpos+1;
        if(p.pos>=0&&p.pos<=100000&&!vis[p.pos])
        q.push(p);
        p.pos=cpos*2;
        if(p.pos>=0&&p.pos<=100000&&!vis[p.pos])
        q.push(p);
    }
    cout<<res<<endl;
}
