#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
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
int r, c;
#define MAXN 1001
void solve();
int mb[10][10000];
int total = 0;
int main()
{
    //    ios::sync_with_stdio(false);
    while (~scanf("%d%d", &r, &c) && r)
        {
            RUP(i, 0, r - 1)
            RUP(j, 0, c - 1)
            scanf("%d", &mb[i][j]);
            solve();
        }
}
int countall()
{
    int res = 0;
    RUP(j, 0, c - 1)
    {
        int tmp1 = 0;
        RUP(i, 0, r - 1)
        if (mb[i][j]) tmp1 += 1;
        res += max(tmp1, r - tmp1);
    }
    return res;
}

int maxmb = 0;
void dfs(int l)
{
    if (l == r - 1)
        {
            maxmb = max(maxmb, countall());
            RUP(j, 0, c - 1) mb[l][j] = !mb[l][j];
            maxmb = max(maxmb, countall());
            RUP(j, 0, c - 1) mb[l][j] = !mb[l][j];
        }
    else
        {
            dfs(l + 1);
            RUP(j, 0, c - 1) mb[l][j] = !mb[l][j];
            dfs(l + 1);
            RUP(j, 0, c - 1) mb[l][j] = !mb[l][j];
        }
}
void solve()
{
    maxmb = 0;
    dfs(0);
    printf("%d\n", maxmb);
}
