class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long t = k;
        long long ans = 0;
        long long cur = 0;
        long long MOD = 1e9 + 7;
        
        for (int i = 0; i < nums.size(); i++) {
            if (k - nums[i] >= 0) {
                k = k - nums[i];
            } else {
                long long needed = nums[i] - k;
                long long n = (needed + t - 1) / t;
                
                long long last = cur + n;
                long long term1 = (cur + 1 + last);
                long long term2 = n;
                
                if (term1 % 2 == 0) term1 /= 2;
                else term2 /= 2;
                
                term1 %= MOD;
                term2 %= MOD;
                
                long long sum = (term1 * term2) % MOD;
                ans = (ans + sum) % MOD;
                
                k = k + n * t - nums[i];
                cur = last;
            }
        }
        return ans;
    }
};