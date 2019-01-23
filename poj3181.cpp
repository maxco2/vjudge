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
int n, k;
#define MAXN 1001
void solve();

int main()
{
    //    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &k);
    solve();
}

unsigned long long dp[1001];
void solve()
{
    dp[0] = 1;
    RUP(i, 1, k)
    {
        RUP(j, i, n) { dp[j] += dp[j - i]; }
    }
    printf("%llu\n", dp[n]);
}
