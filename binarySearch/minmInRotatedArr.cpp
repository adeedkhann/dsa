class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int comp=nums[high];
        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[mid]>comp){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }return nums[low];
    }
};