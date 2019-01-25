#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
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
int n;
void solve();
int total;
int C(int n, int k)
{
    int res = 1;
    RUP(i, 0, k - 1) res = res * (n - i) / (i + 1);
    return res;
}
int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int cnum[10];
int main()
{
    //    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &total);
    RUP(i, 0, n - 1) cnum[i] = C(n - 1, i);
    solve();
}
void solve()
{
    int res;
    do
        {
            res = 0;
            RUP(i, 0, n - 1) res += cnum[i] * nums[i];
            if (res == total)
                {
                    RUP(i, 0, n - 2) printf("%d ", nums[i]);
                    printf("%d\n", nums[n - 1]);
                    break;
                }
        }
    while (next_permutation(nums, nums + n));
}
