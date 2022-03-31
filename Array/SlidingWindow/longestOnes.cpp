class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0; int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (!nums[right]) k --;
            while (k < 0) {
                if (!nums[left]) k ++;
                left ++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};