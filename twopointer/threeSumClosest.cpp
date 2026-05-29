class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int closest=0,diff=INT_MAX;
        for( int i=0;i<nums.size()-1;i++){
            int left=1+i;
            int right = nums.size()-1;
            while(left<right){
                int currSum = nums[i]+nums[left]+nums[right];
                int currdiff = abs(target-currSum);
                if(currdiff<diff){
                    diff=currdiff;
                    closest= currSum;
                }
                if (currSum > target) {
                    right--;
                } else if (currSum < target) {
                    left++;
                } else {
                    return currSum;
                }


            }
        }return closest;
    }
};