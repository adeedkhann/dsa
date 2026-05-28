
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int j = nums.size()-1;
        int i=0;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == target){
                return {i,j};
            }else if(sum> target){
                j--;
            }else{
                i++;
            }
        }return {};
    }
};