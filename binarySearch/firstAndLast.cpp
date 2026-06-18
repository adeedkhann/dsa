class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        int low = 0;
        int high = nums.size()-1;
        int first = INT_MAX;
        int second = INT_MIN;
        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }else if (nums[mid]>target){
                high = mid -1;
            }else{
                first = min(first , mid);
                high = mid-1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low<=high){
            int mid = low +(high -low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                second = max(second , mid);
                low = mid+1;
            }
        }
        if(first == INT_MAX &&  second ==INT_MIN  ){
            return {-1,-1};
        }else{
            return {first , second};
        }


    }
};