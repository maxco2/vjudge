#include <algorithm>
#include <cstdio>
using namespace std;
int tri[351][351];
int N;
int dp[2][351];
// dp[n,i]=dp[n-1,i/2]+tri[i]
int solve()
{
    if (N == 1) return tri[1][1];
    int cur = 0;
    dp[cur][1] = tri[1][1];
    cur = !cur;
    int sum = -1;
    for (int i = 2; i <= N; ++i, cur = !cur)
        for (int j = 1; j <= i; ++j)
            {
                // 1->1,2
                // 2->2,3
                dp[cur][j] =
                    max(dp[!cur][j] + tri[i][j], dp[!cur][j - 1] + tri[i][j]);
                sum = max(sum, dp[cur][j]);
            }
    return sum;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            scanf(" %d", &tri[i][j]);
    printf("%d\n", solve());
}
