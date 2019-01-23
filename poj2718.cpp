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
int n, k;
#define MAXN 1001
void solve();
char nums[11];
int total = 0;
int main()
{
    //    ios::sync_with_stdio(false);
    scanf("%d", &n);
    char ch;
    while ((ch = getchar()) != '\n')
        ;
    while (n--)
        {
            memset(nums, 0, sizeof(nums));
            total = 0;
            while ((ch = getchar()) != '\n')
                {
                    if (isspace(ch)) continue;
                    nums[total++] = ch;
                }
            solve();
        }
}
int getint(int st, int ed)
{
    int res = 0;
    if (st != ed && nums[st] == '0') return 99999999;
    RUP(i, st, ed) { res = res * 10 + (nums[i] - '0'); }
    DEBUG(res);
    return res;
}
int mid;
int diff()
{
    int diff = fabs(getint(0, mid) - getint(mid + 1, total - 1));
    return diff;
}
map<string, int> dp;
void solve()
{
    int res = 99999999;
    if (total == 2)
        res = fabs(nums[0] - nums[1]);
    else
        {
            string hash_v;
            mid = total - 1 >> 1;
            bool check = (mid + 1) != (total - 1);
            hash_v = string(nums);
            if (dp.find(hash_v) != dp.end())
                {
                    res = dp[hash_v];
                    printf("%d\n", res);
                    return;
                }
            do
                {
                    if (nums[0] == '0' || (check && nums[mid + 1] == '0'))
                        continue;
                    res = min(res, diff());
                }
            while (next_permutation(nums, nums + total));
            dp[hash_v] = res;
        };
    printf("%d\n", res);
}
