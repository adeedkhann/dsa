class Solution {
        
        
    int getCows(const vector<int>stalls , int dist){
        int i = 0;
        int cows=1;
        int j=1;
        while(j<stalls.size()){
            if(stalls[j] - stalls[i] >= dist){
                cows++;
                i=j;
                j++;
            }else{
                j++;
            }
        } return cows;
            
    }
    
    
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin() , stalls.end());
        int low =1;
        int high =0;
        int posmin=0;
        int posmax=0;
        
        for(int i = 0;i<stalls.size();i++){
            posmax = max(posmax , stalls[i]);
            posmin = min(posmin , stalls[i]);
            
        }
        high = posmax-posmin;
        
        int ans =1;
        while(low<=high){
            int mid = low +(high-low)/2;
            
            int cows = getCows(stalls , mid);
            if(cows>=k){
                ans = mid;
                low = mid+1;
                
            }else{
                high = mid-1;
            }
        }
        return ans;
        
        
    }
};