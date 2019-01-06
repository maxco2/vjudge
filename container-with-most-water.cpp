/* Container With Most Water
 *
 * [Medium] [AC:41.2% 289.7K of 703.5K] [filetype:cpp]
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the
 * two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
 * together with x-axis forms a container, such that the container
 * contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 * In this case, the max area of water (blue section) the container can
 * contain is 49.
 *
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 *
 * Output: 49
 *
 * [End of Description] */
class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        // dp[1..n]=max(min(h[i],h[j])*(j-i))
        int l = 0, r = h.size() - 1;
        int res = 0;
        // n-1
        while (l <= r)
            {
                res = max(res, min(h[l], h[r]) * (r - l));
                if (h[l] < h[r])
                    l++;
                else
                    r--;
            }
        return res;
    }
};
