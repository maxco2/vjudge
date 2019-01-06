/* Two Sum
 *
 * [Easy] [AC:39.7% 1.3M of 3.3M] [filetype:cpp]
 *
 * Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you
 * may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 *
 * return [0, 1].
 *
 * [End of Description] */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> s;
        int idx = 0;
        for (auto i : nums)
            s.insert({i, idx++});
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i)
            {
                int left = target - nums[i];
                if (s.find(left) != s.end() && s[left] != i)
                    {
                        res.push_back(i);
                        res.push_back(s[left]);
                        return res;
                    }
            }
        return res;
    }
};
