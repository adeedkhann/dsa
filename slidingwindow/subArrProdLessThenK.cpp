class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1) return 0;

        int windprod= 1;
        int count =0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            windprod *= nums[right];

            while(windprod >=k){
                windprod /=nums[left];
                left++;
            }
            if(windprod<k){
                count += (right - left +1);
            }
            else{
                windprod /= nums[right];
                left++;
            }
        }return count;
    }
};