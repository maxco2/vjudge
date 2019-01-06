/* Longest Palindromic Substring
 *
 * [Medium] [AC:25.9% 434.6K of 1.7M]
 * [filetype:cpp]
 *
 * Given a string s, find the longest palindromic
 * substring in s. You may assume that the
 * maximum length of s is 1000.
 *
 * Example 1:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 *
 * [End of Description] */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty()) return "";
        auto check = [&s](int l, int r) {
            if (l == r) return true;
            while (l < r)
                {
                    if (s[l++] != s[r--]) return false;
                }
            return true;
        };
#define MAXR 2
#define MAXC 1005
        int dp[MAXR][MAXC];
        int lcs = 0;
        int l = 0, r = 0;
        memset(dp, 0, sizeof(int) * MAXR * MAXC);
        auto sz = s.size();
        int cur = 0;
        for (int i = 0; i < sz; ++i, cur = !cur)
            {
                for (int j = sz - 1; j >= 0; j--)
                    {
                        int next = !cur;
                        if (s[j] == s[i])
                            {
                                int tmplen = dp[next][sz - j] =
                                    dp[cur][sz - j - 1] + 1;
                                if (dp[next][sz - j] > lcs &&
                                    check(i - tmplen + 1, i))
                                    {
                                        lcs = dp[next][sz - j];
                                        l = i;
                                        r = j;
                                    }
                            }
                        else
                            {
                                dp[next][sz - j] = 0;
                            }
                    }
            }
        return string{s.begin() + l - lcs + 1, s.begin() + l + 1};
    }
};
