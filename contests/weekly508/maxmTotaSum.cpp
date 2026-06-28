/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} mul
 * @return {number}
 */
var maxSum = function(nums, k, mul) {
    let totalSum = 0;
    nums.sort((a,b)=> b-a);
    for(let i = 0;i<k;i++){
            if(mul>0){
                totalSum = totalSum + (nums[i]* mul);
            }else{
                totalSum += nums[i];
            }
            mul--;
        }return totalSum;
    
};

// class Solution {
// public:
//     long long maxSum(vector<int>& nums, int k, int mul) {
//         long long totalSum = 0;
//         sort(nums.begin() , nums.end());
//         reverse(nums.begin() , nums.end());
//         for(long long i = 0;i<k;i++){
//             if(mul>0){
//                 totalSum = totalSum + (nums[i]* mul);
//             }else{
//                 totalSum += nums[i];
//             }
//             mul--;
//         }return totalSum;
//     }
// };