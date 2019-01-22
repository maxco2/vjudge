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
int t, a, s, b;
#define MAXN 1001
typedef pair<int, int> pii;
int ants[MAXN];
void solve();

int main()
{
    //    ios::sync_with_stdio(false);
    scanf("%d%d%d%d", &t, &a, &s, &b);
    int fam;
    RUP(i, 1, a)
    {
        scanf("%d", &fam);
        ants[fam]++;
    }
    solve();
}
//%10e6
// dp[T][X]=sum(dp[T-1][X-0..num[T]])
#define MOD 1000000
int dp[2][100001];
void solve()
{
    int now = 0, pre = 1;
    int res = 0;
    dp[pre][0] = dp[now][0] = 1;
    RUP(i, 1, t)
    {
        dp[now][1] = i;
        int bound = ants[i];
        RUP(j, 2, bound)
        {
            dp[now][j] = dp[pre][j] + dp[now][j - 1];
            dp[now][j] %= MOD;
        }
        RUP(j, bound + 1, b)
        {
            dp[now][j] =
                dp[pre][j] + dp[now][j - 1] - dp[pre][j - 1 - bound] + MOD;
            dp[now][j] %= MOD;
        }
        swap(now, pre);
    }
    RUP(i, s, b)
    {
        res += dp[pre][i];
        res %= MOD;
    }
    printf("%d\n", res);
}
