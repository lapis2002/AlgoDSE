class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0; int right = 0; int cnt = 0;
        int n = s.length();
        int res = 0;
        
        int sub_length;
        for (; right < n; ++ right) {
            if (freq[s[right]-'A'] == 0) cnt ++;
            freq[s[right]-'A'] ++;

            if (cnt <= k) res = max(res, right - left + 1);
            else 
                while (cnt > k) {
                    freq[s[left]-'A'] --;
                    if (freq[s[left]-'A'] <= 0) cnt --;
                    left ++;
                }
        }
        return res;
    }
};