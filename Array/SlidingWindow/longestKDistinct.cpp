class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0; int right = 0; int cnt = 0;
        int n = s.length();
        int res = 0;
        
        for (; right < n; ++ right) {
            if (freq.find(s[right]) == freq.end() ||
                freq[s[right]] == 0) cnt ++;
            if (freq.find(s[right]) != freq.end()) freq[s[right]] ++;
            else freq.insert({s[right], 1});

            if (cnt <= k) {
                res = max(res, right - left + 1);
            }
            else 
                while (cnt > k) {
                    freq[s[left]] --;
                    if (freq[s[left]] <= 0) cnt --;
                    left ++;
                }
        }
        return res;
    }
};