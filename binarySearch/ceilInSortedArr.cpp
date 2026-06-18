// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        
    int low = 0;
    int high = arr.size()-1;
    int ans = INT_MAX;
    while(low<=high){
        int med = low +(high-low)/2;
        if(arr[med]==x){
            ans = min(ans , med);
            high = med-1;
        }else if (arr[med]>x ){
            ans = min(ans , med);
            high = med-1;
        }else{
            low = med+1;
        }
    }return ans == INT_MAX ? -1 : ans;
        
    }
};