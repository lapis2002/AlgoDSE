class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = collections.Counter()
        left = 0
        n = len(s)
        max_f = 0
        res = 0
        for right, ch in enumerate(s):
            freq[ch] += 1
            max_f = max(max_f, freq[ch])
            
            len_substring = right - left + 1
            if len_substring - max_f > k:
                res = max(res, right-1-left+1)
                freq[s[left]] -= 1
                left += 1
                max_f = max(freq.values())
            
        return max(res, right-left+1)