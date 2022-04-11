class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt_zero = 0;
        for (auto &x: nums) if (x==0) cnt_zero ++;
        
        if (cnt_zero == 1) {
            int p = 1, ind_zero;
            vector<int> res(n, 0);
            for (int i = 0; i < n; ++i) {
                if (nums[i] != 0) p *= nums[i];
                else ind_zero = i;
            }
            res[ind_zero] = p;
            return res;
        }
        else if (cnt_zero > 1) return vector<int> (n, 0);
        
        vector<int> res (n, 1);
        vector<int> left_prod (n,1);
        vector<int> right_prod (n,1);

        for (int i = 1; i < n; ++i) {
            left_prod[i] = left_prod[i-1]*nums[i-1];       
        }
        
        for (int i = n-2; i >= 0; --i) {
            right_prod[i] = right_prod[i+1]*nums[i+1];
        }
        for (int i = 0; i < n; ++i) res[i] = left_prod[i] * right_prod[i];
        
        return res;
    }
};