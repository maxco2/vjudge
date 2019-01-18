#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif
#define RANGE_FOR(v, st, ed) for (int v = st; v < ed; ++v)
#define RUP(v, st, ed) for (int v = st; v <= ed; ++v)
#define RDO(v, st, ed) for (int v = st; v >= ed; --v)
#define RFOR(v, ed) for (int v = 0; v < ed; ++v)
using namespace std;
int n, m, r;
#define MAXN 1001
struct Alpha
{
    int it;
    int del;
    Alpha() : it(0), del(0) {}
    Alpha(int i, int d) : it(i), del(d) {}
};
Alpha al[26];
string mystr;
void solve();
int dp[2001][2001];
int dfs(int st, int ed);
bool huiwen(int st, int ed, int &newst, int &newed);
int main()
{
    //    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    char c;
    cin >> n >> m >> mystr;
    RFOR(i, n)
    {
        int it, del;
        scanf(" %c%d%d", &c, &it, &del);
        al[c - 'a'].it = it;
        al[c - 'a'].del = del;
    }
    cout << dfs(0, m) << endl;
}
void solve() {}
bool huiwen(int st, int ed, int &newst, int &newed)
{
    if (st >= ed) return true;
    int mid = (ed - 1 - st) / 2;
    RUP(i, 0, mid)
    {
        if (mystr[i + st] != mystr[ed - 1 - i])
            {
                newst = i + st;
                newed = ed - i;
                return false;
            }
    }
    return true;
}
inline int insval(char c) { return al[c - 'a'].it; }
inline int delval(char c) { return al[c - 'a'].del; }
int dfs(int st, int ed)
{
    if (dp[st][ed] != -1)
        {
            return dp[st][ed];
        }
    int newst = st, newed = 0;
    if (huiwen(st, ed, newst, newed))
        {
            dp[st][ed] = 0;
            return 0;
        }
    if (newst != st)
        {
            st = newst;
            ed = newed;
        }
    // left add
    int dfstail = dfs(st, ed - 1);
    int dfshead = dfs(st + 1, ed);
    int res1 = dfstail + min(insval(mystr[ed - 1]), delval(mystr[ed - 1]));
    int res2 = dfshead + min(delval(mystr[st]), insval(mystr[st]));
    int minres = min(res1, res2);
    dp[st][ed] = minres;
    return minres;
}
