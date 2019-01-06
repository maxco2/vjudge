/* Count Numbers with Unique Digits
 *
 * [Medium] [AC:46.4% 56.5K of 121.8K] [filetype:cpp]
 *
 * Given a non-negative integer n, count all numbers with unique digits,
 * x, where 0 ≤ x < 10n.
 *
 * Example:
 *
 * Input: 2
 *
 * Output: 91
 *
 * Explanation: The answer should be the total numbers in the range of 0 ≤
 * x < 100,
 *
 *              excluding 11,22,33,44,55,66,77,88,99
 *
 * [End of Description] */
constexpr int dp[11] = {1,      10,     91,      739,     5275,   32491,
                        168571, 712891, 2345851, 5611771, 8877691};
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        // long long maxn=pow(10,n);
        if (n <= 10) return dp[n];
        return dp[10];
    }
};
