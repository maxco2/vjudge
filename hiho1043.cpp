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
void solve();
int main()
{
    scanf("%d%d", &n, &m);
    RFOR(i, n) { scanf(" %d%d", nd + i + 1, value + i + 1); }
    solve();
}
void solve()
{
    RUP(i, 1, n)
    RUP(j, nd[i], m) { dp[j] = max(dp[j], dp[j - nd[i]] + value[i]); }
    printf("%d\n", dp[m]);
}
