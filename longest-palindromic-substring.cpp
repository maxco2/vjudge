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
// string res;
/*int ml=0;
int maxl=0,maxr=0;
int l=0,r=0;
auto sz=s.size();

for(int i=0;i<sz;++i)
{
   int cl=0;
   l=r=i;
   for(int wnd=0;wnd+i<sz;wnd++)
       if(s[i]==s[i+wnd])
       {
          if(check(i+1,i+wnd-1))
          {
              cl=wnd+1;
              if(cl>ml)
              {
                  maxl=i;
                  maxr=i+wnd;
                  ml=cl;
              }
          }

       }
}
for(;maxl<=maxr;++maxl)
    res+=s[maxl];
return res;*/
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

                // int next=cur==1?0:1;
                for (int j = sz - 1; j >= 0; j--)
                    {
                        int next = !cur;
                        // int cur=i;
                        if (s[j] == s[i])
                            {
                                // printf("i:%d,j:%d\n",i,j);
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
                        // printf("dp[%d][%d]=%d\n",next,sz-j,dp[next][sz-j]);
                    }
            }
        // cout<<"l"<<l<<",r"<<r<<",lcs"<<lcs<<endl;
        return string{s.begin() + l - lcs + 1, s.begin() + l + 1};
    }
};
