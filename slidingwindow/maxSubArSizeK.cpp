class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        int i =0;
        int j=k-1;
        int maxSum=INT_MIN;
        int windSum=0;
        for(int z =0;z<=j;z++){
            windSum +=arr[z];
        }
            maxSum= max(windSum,maxSum);
        while(j<arr.size()-1){
            windSum = windSum - arr[i] ;
            windSum = windSum + arr[j+1];
            maxSum= max(windSum,maxSum);
        i++;
        j++;
        
        
        }
        
        return maxSum;
        
    }
};