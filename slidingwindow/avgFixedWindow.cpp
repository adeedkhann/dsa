class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left =0;
        int right = k-1;
        double sum =0;
        double maxsum=0;
        double avg = 0;
        for(int i =0;i<=right;i++){
            sum += nums[i];
        }
        maxsum = sum ;
        while(right<nums.size()-1){
            sum -=nums[left];
            sum+=nums[right+1];
            left++;
            right++;

            if(maxsum<sum){
                maxsum = sum ;
            }
        }return maxsum/k;
    }
};