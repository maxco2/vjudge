#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
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
int n, m;
#define MAXN 100001
int nd[501];
int value[501];
int dp[MAXN];
int perm[501];
void naiveSolve();
void solve();
void bfssolve();
int main()
{
    scanf("%d%d", &n, &m);
    RFOR(i, n) { scanf(" %d%d", nd + i + 1, value + i + 1); }
    // naiveSolve();
    // solve();
    bfssolve();
}
void bfssolve()
{
    RUP(i, 1, n) perm[i] = i;
    sort(perm + 1, perm + n + 1, [](int t1, int t2) {
        return value[t1] * nd[t2] > value[t2] * nd[t1];
    });
    struct St
    {
        int allvalue = 0;
        int left = m;
        int cur = 1;
        St() {}
        St(int a, int l, int c) : allvalue(a), left(l), cur(c) {}
        bool operator<(const St &that) const
        {
            return allvalue < that.allvalue;
        }
        int trygetmost()
        {
            St that{*this};
            while (that.cur <= n && that.left > nd[perm[that.cur]])
                {
                    that.left -= nd[perm[that.cur]];
                    that.allvalue += value[perm[that.cur++]];
                }
            if (that.cur <= n)
                that.allvalue +=
                    that.left * value[perm[that.cur]] / nd[perm[that.cur]];
            return that.allvalue;
        }
    };
    priority_queue<St> q;
    q.push(St{});
    int res = 0;
    while (!q.empty())
        {
            auto curst = q.top();
            q.pop();
            if (curst.cur == n + 1) // finish  choose
                {
                    res = max(res, curst.allvalue);
                    continue;
                }
            if (curst.left >= nd[perm[curst.cur]])
                q.push(St{curst.allvalue + value[perm[curst.cur]],
                          curst.left - nd[perm[curst.cur]], curst.cur + 1});
            if (curst.trygetmost() > res)
                {
                    curst.cur += 1;
                    q.push(curst);
                }
        }
    printf("%d\n", res);
}
void solve()
{
    RANGE_FOR(i, 1, n + 1)
    for (int j = m; j >= nd[i]; --j)
        dp[j] = max(dp[j], dp[j - nd[i]] + value[i]);
    printf("%d\n", dp[m]);
}
void naiveSolve()
{
    // f[i,m]=max{f[i-1,m],f[i-1,m-nd[i]]+v[i]}
    int naivedp[501][MAXN];
    for (int i = 1; i <= n; ++i)
        if (nd[i] > m)
            memcpy(naivedp[i], naivedp[i - 1], sizeof(int) * (m + 1));
        else
            {
                memcpy(naivedp[i], naivedp[i - 1], sizeof(int) * (nd[i]));
                for (int cost = nd[i]; cost <= m; ++cost)
                    naivedp[i][cost] =
                        max(naivedp[i - 1][cost],
                            naivedp[i - 1][cost - nd[i]] + value[i]);
            }
    printf("%d\n", naivedp[n][m]);
}

