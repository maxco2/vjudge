#include <algorithm>
#include <cstdio>
#include <cstdlib>
#ifdef _DEBUG
#include <iostream>
#define DEBUG(x) cout << #x << x << endl;
#else
#define DEBUG(x)
#endif

using namespace std;
int n, k;
#define MAXN 100005
int nums[MAXN];
int perm[MAXN];
bool cmpl(const int a, const int b) { return nums[a] <= nums[b]; }
void solve(int num)
{
    int l = 0, r = 1, resl = l, resr = r, sum = 0, asum = 0;
    int diff = 2 * 10e8 + 1, ndiff = -1;
    while (r <= n)
        {
            sum = nums[perm[r]] - nums[perm[l]];
            DEBUG(sum);
            ndiff = abs(abs(sum) - num);
            if (ndiff < diff)
                {
                    diff = ndiff;
                    resr = r;
                    resl = l;
                    asum = abs(sum);
                }
            if (sum < num || l == r - 1)
                ++r;
            else
                ++l;
        }
    int bl = min(perm[resl], perm[resr]);
    int br = max(perm[resl], perm[resr]);
    printf("%d %d %d\n", asum, bl + 1, br);
}
int main()
{
    while (~scanf("%d%d", &n, &k) && (n != 0 && k != 0))
        {
            int sum = 0;
            perm[0] = 0;
            for (int i = 1; i <= n; ++i)
                {
                    scanf(" %d", nums + i);
                    sum += nums[i];
                    nums[i] = sum;
                    perm[i] = i;
                }
            sort(perm, perm + n + 1, cmpl);
            for (int i = 0; i < k; ++i)
                {
                    int num;
                    scanf(" %d", &num);
                    solve(num);
                }
        }
    return 0;
}
