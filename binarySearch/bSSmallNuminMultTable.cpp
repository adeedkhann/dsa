class Solution {

    int getCount(int m , int n , int mid){
        int row = m;
        int col = 1;
        int count = 0;
        while(col<=n && row>=1){
            int val = col*row;
            if(val <= mid){
                count = count + row;
                col++;
            }else{
                row--;
            }
        }return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int res = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            int val = getCount(m,n,mid);
            if(val>=k){
                high = mid-1;
                res = mid;
            }else{
                low = mid+1;
            }
        }return res;
    }
};