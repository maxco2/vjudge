#include <algorithm>
#include <cstdio>
#include <cstdlib>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif
#define RANGE_FOR(v, st, ed) for (int v = st; v < ed; ++v)
#define RFOR(v, ed) for (int v = 0; v < ed; ++v)

using namespace std;
int n;
int dp[1000001];
void solve()
{
    // 1 1 1 1
    // 1 1 2
    // 2 2
    // 4
    dp[0] = 0;
    dp[1] = 1;
    RANGE_FOR(i, 2, n + 1)
    if (i % 2 != 0)
        dp[i] = dp[i - 1];
    else
        dp[i] = dp[i - 1] + dp[i >> 1];
    printf("%d\n", dp[n]);
}
int main()
{
    scanf("%d", &n);
    solve();
}

