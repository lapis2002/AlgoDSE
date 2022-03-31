class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i = 0
        left = 0
        res = 0
        n = len(nums)
        for right in range(n):
            if nums[right] == 0:
                k -= 1
            while k < 0:
                if nums[left] == 0:
                    k += 1
                left += 1
            res = max(right - left + 1, res)
        return res