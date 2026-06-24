class Solution {
    
    bool isCorrect(vector<int>books , int lim , int st){
        int k =1;
        int page =0;
        for(int i = 0;i<books.size();i++){
            if((page + books[i])<=lim){
                page += books[i];
            }else{
                k++;
                page=books[i];
                if(k>st){
                    return false;
                }
            }
        }return true;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        int low =0;
        int high = 0;
        int res = -1;
        for(int i = 0;i<arr.size();i++){
            low = max(low , arr[i]);
            high += arr[i];
        }
        
        while(low<=high){
            int mid = low +(high - low)/2;
            int curr = isCorrect(arr , mid , k);
            if(curr){
                res = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }return res;
    }
};