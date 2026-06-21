class Solution {

int getBouquet(int x , const vector<int>& arr, int k){
    int count = 0;
    int curr=0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]<=x){
            curr++;
            if(curr== k){
                count++;
                curr=0;
            }
        }else{
                curr=0;
            }
    }return count;
}

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 0;
        int high = 0;
        int count;
        int ans = -1;
        for(int i = 0 ; i<bloomDay.size();i++){
            high = max(high , bloomDay[i]);
        } 

        while(low<=high){
            int mid = low + (high - low)/2;
            int count = getBouquet(mid ,bloomDay , k);
            if(count<m){
                low = mid+1;
            }else if(count >= m){
                ans = mid;
                high = mid-1;

            }
        }return ans;
    }
};