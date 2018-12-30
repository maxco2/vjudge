#include<vector>
#include<map>
using mii=map<int,int>;
using vint=vector<int>;
vint sz;
vint top;
vint heavy;
vint dep;
vint fa;
vint sumSonWL;
mii stime;
mii stimeToPos;
void dfs1(int pos, int father, int depth)
{
    dep[pos] = depth;
    fa[pos] = father;
    sz[pos] = 1;
    for (auto i : tree[pos].links)
        if (i != fa[i])
        {
            dfs1(i, pos, depth + 1);
            sz[pos] += sz[i];
            if (heavy[pos] == -1 || sz[i] > sz[heavy[pos]])
                heavy[pos] = i;
        }
}

void dfs2(int pos,int topLinkPos)
{
    static int count=0;
    top[pos]=topLinkPos;//the heavy/light link ansestor
    stime[pos]=count;
    stimeToPos[count++]=pos;
    if(heavy[pos]==-1) return;
    dfs2(heavy[pos],topLinkPos);//set all headvy son top value to stHeavypos
    for(auto i:tree[pos].links)
    {
        if(i!=heavy[pos] && i!=fa[pos])
            dfs2(i,i);
    }
}

int query(int st,int left,int right)
{
    return 0;
}

void update(int st,int x,int y,int add)
{

}

int queryPath(int x,int y)
{
    int ans=0;
    int tx=top[x];
    int ty=top[y];
    while(tx!=ty)
    {
        if(dep[tx]>=dep[ty])
        {
            ans+=query(1,stime[tx],stime[ty]);
            x=fa[tx];
        }
        else
        {
            ans+=query(1,stime[ty],stime[tx]);
            y=fa[ty];
        }
        tx=top[x];
        ty=top[y];
    }
    if(x!=y)
    {
        if(stime[x]<stime[y])
        ans+=query(1,stime[x],stime[y]);
        else
        ans+=query(1,stime[y],stime[x]);
    }
    else
    ans+=query(1,stime[x],stime[y]);
    return ans;
}

void updatePath(int x,int y,int weight)
{
    
    int tx=top[x];
    int ty=top[y];
    while(tx!=ty)
    {
        if(dep[tx]>dep[ty])
        {
            update(1,stime[tx],stime[x],weight);
            x=fa[tx];
        }
        else
        {
            update(1,stime[ty],stime[y],weight);
            y=fa[ty];
        }
        tx=top[x];
        ty=top[y];
    }
    if(x!=y)
    {
        if(stime[x]<stime[y])
        update(1,stime[x],stime[y],weight);
        else
        update(1,stime[y],stime[x],weight);
    }
    else
    update(1,stime[x],stime[y],weight);
}