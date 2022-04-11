class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left = 0
        n = len(nums)
        if n < 2:
            return n
        for right in range(1, n): 
            if nums[right] != nums[left]:
                left += 1
                nums[left], nums[right] = nums[right], nums[left]
        return left+1