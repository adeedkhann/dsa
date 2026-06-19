class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low =0;
        int high = nums.size()-2;

        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[mid]>nums[mid+1]){
                high  = mid-1;
            }else{
                low = mid+1;
            }
        }return low;
    }
};