/* Median of Two Sorted Arrays
 *
 * [Hard] [AC:24.9% 354.1K of 1.4M] [filetype:cpp]
 *
 * There are two sorted arrays nums1 and nums2 of size m and n
 * respectively.
 *
 * Find the median of the two sorted arrays. The overall run time
 * complexity should be O(log (m+n)).
 *
 * You may assume nums1 and nums2 cannot be both empty.
 *
 * Example 1:
 *
 * nums1 = [1, 3]
 *
 * nums2 = [2]
 *
 * The median is 2.0
 *
 * Example 2:
 *
 * nums1 = [1, 2]
 *
 * nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 * [End of Description] */
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto sz1 = nums1.size();
        auto sz2 = nums2.size();
        auto sz = sz1 + sz2;
        int l = 0, r = 0;
        if (sz % 2 == 0)
            {
                r = sz / 2;
                l = r - 1;
            }
        else
            r = l = (0 + sz - 1) / 2;
        // cout<<"l"<<l<<",r"<<r;
        double ft = 0, sd = 0;
        int st1 = 0, st2 = 0, idx = 0;
        while (st1 < sz1 && st2 < sz2 && (idx) <= r)
            {
                if (nums1[st1] < nums2[st2])
                    {
                        if (idx == l) ft = nums1[st1];
                        if (idx == r) sd = nums1[st1];
                        ++st1;
                    }
                else
                    {
                        if (idx == l) ft = nums2[st2];
                        if (idx == r) sd = nums2[st2];
                        // cout<<"ffff";
                        st2++;
                    }
                idx++;
            }
        while (st1 < sz1 && (idx) <= r)
            {
                if (idx == l) ft = nums1[st1];
                if (idx == r) sd = nums1[st1];
                ++st1;
                idx++;
            }
        while (st2 < sz2 && (idx) <= r)
            {
                if (idx == l) ft = nums2[st2];
                if (idx == r) sd = nums2[st2];
                ++st2;
                idx++;
            }
        return (ft + sd) / 2.0;
    }
};
