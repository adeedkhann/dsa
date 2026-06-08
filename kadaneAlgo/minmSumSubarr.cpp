// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int ans ;
        int sum;
        int curval;
        for(int i =0;i<a.size();i++){
            sum +=a[i];
            curval=a[i];
            
            sum = min(sum , curval);
            
            ans = min(sum , ans);
        }
        return ans;
        
    }
};
