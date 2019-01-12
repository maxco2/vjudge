#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif
#define RANGE_FOR(v, st, ed) for (int v = st; v < ed; ++v)
#define RFOR(v, ed) for (int v = 0; v < ed; ++v)
using namespace std;
int n, m;
#define MAXN 100001
int nd[501];
int value[501];
int dp[MAXN];
void naiveSolve();
void solve();
int main()
{
    scanf("%d%d", &n, &m);
    RFOR(i, n) { scanf(" %d%d", nd + i + 1, value + i + 1); }
    // naiveSolve();
    solve();
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

