class Solution:
    def longestKDistinct(self, s: str, k: int) -> int:
        freq = collections.Counter()
        left = 0
        cnt = 0
        res = 0
        for right, ch in enumerate(s):
            if freq[ch] == 0: cnt += 1
            freq[ch] += 1

            if cnt <= k:
                res = max(res, right - left + 1)
            else:
                while cnt > k:
                    freq[s[left]] -= 1
                    if freq[s[left]] <= 0: cnt -= 1
                    left += 1
        return res