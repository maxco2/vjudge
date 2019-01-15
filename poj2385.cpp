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
int n, w;
#define MAXN 1001
typedef pair<int, int> pii;
int apple[MAXN];
int tree[MAXN];
int newn = 0;
void solve();
int main()
{
    scanf("%d%d", &n, &w);
    int cur;
    int last = -1;
    RFOR(i, n)
    {
        scanf(" %d", &cur);
        if (cur == last)
            apple[newn]++;
        else
            {
                apple[++newn]++;
                tree[newn] = cur - 1;
                last = cur;
            }
    }
    solve();
}
int dp[2][31];
// dp[i][j]=max(dp[i-1][j]+apple[i],dp[i-1][j-1]+apple[i])//j [1,j]
void solve()
{
    int res = 0;
    int now = 0, pre = 1;
    if (newn == 1)
        res = apple[1];
    else
        {
            RUP(i, 1, newn)
            {
                RUP(j, 0, min(w, i))
                {
                    if (j == 0)
                        {
                            if (tree[i] == j % 2)
                                dp[now][j] = dp[pre][j] + apple[i];
                            else
                                dp[now][j] = dp[pre][j];
                        }
                    else
                        {
                            if (tree[i] == j % 2)
                                dp[now][j] = max(dp[pre][j - 1] + apple[i],
                                                 dp[pre][j] + apple[i]);
                            else
                                dp[now][j] = max(dp[pre][j], dp[pre][j - 1]);
                        }
                    res = max(res, dp[now][j]);
                }
                swap(now, pre);
            }
        }
    printf("%d\n", res);
}
