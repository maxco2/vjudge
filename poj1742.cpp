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
int n, m;
#define MAXN 1001
typedef long long ll;
struct Coin
{
    int v;
    int num;
    Coin() : v(0), num(0) {}
};
Coin coin[101];
void solve();
int main()
{
    while (~scanf("%d%d", &n, &m) && n)
        {
            RUP(i, 1, n) { scanf("%d", &coin[i].v); }
            RUP(i, 1, n) { scanf("%d", &coin[i].num); }
            solve();
        }
}

typedef int dp_t;
dp_t dp[2][100005];
// dp[i][j]  选择前i个物品,可以构成j的组合数
bool pred(int i) { return i; }
void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    int now = 0, pre = 1;
    RUP(i, 1, n)
    {
        if (coin[i].v <= m)
            {
                copy(dp[pre], dp[pre] + coin[i].v, dp[now]);
                int bound = min(coin[i].v * (coin[i].num + 1), m + 1);
                RUP(j, coin[i].v, bound - 1)
                dp[now][j] = dp[pre][j] + dp[now][j - coin[i].v];
                RUP(j, bound, m)
                dp[now][j] =
                    dp[pre][j] + dp[now][j - coin[i].v] - dp[pre][j - bound];
                swap(now, pre);
            }
        else
            continue;
    }
    printf("%ld\n", count_if(dp[pre] + 1, dp[pre] + m + 1, pred));
}
