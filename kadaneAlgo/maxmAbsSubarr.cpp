class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size()==1) return abs(nums[0]);

        int curmax = nums[0];
        int curmin = nums[0];
        int minsum=nums[0];
        int maxsum = nums[0];;
        for(int i =1;i<nums.size();i++){
            curmax += nums[i];
            curmax= max(nums[i] , curmax);
            maxsum = max(curmax , maxsum);
            curmin +=nums[i];
            curmin = min(curmin , nums[i]);
            minsum = min(minsum , curmin);  
        }return max(maxsum , abs(minsum));
    }
};