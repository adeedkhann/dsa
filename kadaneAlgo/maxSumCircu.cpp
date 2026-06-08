class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {


            int glomax=nums[0];
            int glomin = nums[0];
            int minsum =nums[0];
            int maxsum = nums[0];
            int totalsum = nums[0];


        for(int i=1;i<nums.size();i++){
        
            minsum = min(minsum+nums[i] , nums[i]);
            maxsum = max(maxsum + nums[i] , nums[i] );
            glomax = max(glomax , maxsum);
            glomin = min (glomin , minsum);
            totalsum +=nums[i];
            
        }
        if( glomax <0){
            return glomax;
        }return max( totalsum - glomin , glomax) ;


    }
};