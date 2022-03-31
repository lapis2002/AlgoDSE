class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need, missing = collections.Counter(t), len(t)
        left = 0
        minLeft = 0
        minRight = 0
        for right, c in enumerate(s, 1):
            missing -= need[c] > 0
            need[c] -= 1
            if not missing:
                while left < right and need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1
                if not minRight or right - left <= minRight - minLeft:
                    minLeft = left
                    minRight= right
        return s[minLeft:minRight]