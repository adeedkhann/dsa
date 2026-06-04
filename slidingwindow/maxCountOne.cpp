class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,h=0;

        int maxl=0;
        vector<int> arr(2,0);

        for(h=0;h<nums.size();h++){
            arr[nums[h]]++;
            int len = h-l+1;
            while(arr[0]>k){
                arr[nums[l]]--;
                l++;
                len = h-l+1;
                maxl=max(maxl,len);
            }  maxl=max(maxl,len);
            
        }return maxl;
    }
};