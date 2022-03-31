class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> needs;
        int missing = t.length();
        
        int left = 0; int minLeft = 0; int minRight = 0;
        
        for (auto &ch : s) {
            if (needs.find(ch) != needs.end()) continue;
            else needs.insert({ch, 0});
        }
        
        for (auto &ch : t) {
            if (needs.find(ch) != needs.end()) needs[ch] ++;
            else needs.insert({ch, 1});
            
        }
        for (int right = 0; right < s.length(); ++right) {
            missing -= (needs[s[right]] > 0);
            needs[s[right]] --;
            
            if (!missing) {
                while (left <= right && 
                       needs[s[left]] < 0) {
                    needs[s[left]] ++;
                    left ++;
                }
                if (!minRight || right - left + 1 <= minRight - minLeft) {
                    minRight = right+1;
                    minLeft = left;
                }
            }
        }

        return s.substr(minLeft, minRight - minLeft);
    }
};