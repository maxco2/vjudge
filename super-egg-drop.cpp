/* Super Egg Drop
 *
 * [Hard] [AC:24.3% 4.8K of 19.6K] [filetype:cpp]
 *
 * You are given K eggs, and you have access to a building with N floors
 * from 1 to N.
 *
 * Each egg is identical in function, and if an egg breaks, you cannot
 * drop it again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or
 * below floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop
 * it from any floor X (with 1 <= X <= N).
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with
 * certainty what F is, regardless of the initial value of F?
 *
 * Example 1:
 *
 * Input: K = 1, N = 2
 *
 * Output: 2
 *
 * Explanation:
 *
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F
 * = 0.
 *
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with
 * certainty that F = 1.
 *
 * If it didn't break, then we know with certainty F = 2.
 *
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 *
 * Example 2:
 *
 * Input: K = 2, N = 6
 *
 * Output: 3
 *
 * Example 3:
 *
 * Input: K = 3, N = 14
 *
 * Output: 4
 *
 * Note:
 *
 * 1 <= K <= 100
 *
 * 1 <= N <= 10000
 *
 * [End of Description] */
// dp[k][N]=min(max(dp[k-1][i-1],dp[k][N-i]))+1  1<=i<=n
int dp[101][10001];
class Solution
{
public:
    int getcur(int k, int n, int i)
    {
        if (i < 0 || i > n) return INT_MAX;
        return max(dp[k - 1][i - 1], dp[k][n - i]);
    }
    bool check(int k, int n, int i) { return dp[k - 1][i - 1] > dp[k][n - i]; }

    int superEggDrop(int K, int N)
    {
        for (int i = 1; i <= N; ++i)
            dp[1][i] = i;
        for (int i = 1; i <= K; ++i)
            dp[i][1] = 1;
        for (int k = 2; k <= K; ++k)
            for (int n = 2; n <= N; ++n)
                {
                    dp[k][n] = n + 1;
                    int l = 1, r = n, ans = 1;
                    while (l <= r)
                        {
                            int mid = l + r >> 1;
                            if (check(k, n, mid))
                                ans = mid, r = mid - 1;
                            else
                                l = mid + 1;
                        }
                    dp[k][n] =
                        min(min(getcur(k, n, ans), getcur(k, n, ans - 1)),
                            getcur(k, n, ans + 1)) +
                        1;
                    // for (int i = 2; i <= n; ++i)
                    // dp[k][n] = min(dp[k][n],
                    // max(dp[k - 1][i - 1], dp[k][n - i]) + 1);
                }
        return dp[K][N];
    }
};
