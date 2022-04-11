class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        for (int right = 1; right < n; ++right) {
            if (nums[left] != nums[right]) {
                left += 1;
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        return left + 1;
    }
};