class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long left=0,right=0;
        int result=INT_MAX;
        int sum = 0;
        while(right<nums.size()){
            sum = sum + nums[right];
            while(sum>=target){
                int len = right-left+1;
                result = min(result , len);
                sum-=nums[left];
                left++;
            }right++;

        }return (result == INT_MAX) ? 0 : result;;
    }
};