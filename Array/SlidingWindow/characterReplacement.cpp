class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0; int right = 0; int max_f = 0;
        int n = s.length();
        int res = 0;
        
        int sub_length;
        for (; right < n; ++ right) {
            freq[s[right]-'A'] ++;
            max_f = max(max_f, freq[s[right]-'A']);
            sub_length = right - left + 1;
            if (sub_length - max_f > k) {
                res = max(res, right - 1 - left + 1); // the previous substring is valid
                freq[s[left] - 'A']--;
                left ++;
                
                max_f = *(max_element(freq.begin(), freq.end()));
            } 
        }
        return max(res, right - 1 - left + 1);
    }
};