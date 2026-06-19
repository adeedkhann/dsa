class Solution {
    long long geth(vector<int> &arr , int speed){
        long long h = 0;
        for(int i =0;i<arr.size();i++){
            h = h+ arr[i]/speed;
            if(arr[i]%speed !=0){
                h++;
            }
        }return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int i =0;i<piles.size();i++){
             high = max(high , piles[i]);
        }
        int low =1;
        int res = -1;
        while(low<=high){
            int mid = low + (high -low)/2;
            long long hours = geth(piles , mid);
            if(hours> h){
                low = mid+1;
            }else{
                 high = mid-1;
                 res = mid;
            }
        }return res;
    }
};