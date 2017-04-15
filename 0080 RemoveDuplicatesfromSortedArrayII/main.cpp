/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
 * For example, Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5,
 * with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int len = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            int t_len = 1;
            while (i<nums.size()-1 && nums[i]==nums[i+1])
            {
                ++i; ++t_len;
            }
            nums[len++] = nums[i];
            if (t_len >= 2)
                nums[len++] = nums[i];
        }
        return len;
    }
};