class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        if nums.count(0) == 1:
            p = 1
            res = [0 for i in range(n)]
            for i in range(n):
                if nums[i] != 0:
                    p = p * nums[i]
                else:
                    id = i
            res[id] = p
            return res
        elif nums.count(0) > 1:
            return [0 for i in range(n)]
            
        res = [1 for i in range(n)]
        l = [1 for i in range(n)]
        r = [1 for i in range(n)]
        for i in range(1, n):
            l[i] = l[i-1] * nums[i-1]
        for i in range(n-2, -1, -1):
            r[i] = r[i+1] * nums[i+1]
            # print(l)
            # print(r)
        for i in range(n):
            res[i] = l[i] * r[i]
        return res