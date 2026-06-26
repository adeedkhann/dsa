class Solution {

    int getSmaller (vector<vector<int>> matrix , int mid){
        int row = matrix.size()-1;
        int tcol = matrix[0].size()-1;
        int col = 0;
        int count = 0;
        while(col<=tcol && row>=0){
            
            int val = matrix[row][col];
            if(val>mid){
                row--;
            }else{
                count = count + row+1;
                col++;
            }
        }return count;
    }



public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        int first = matrix[0][0];
        int last  = matrix[row][col];
          int res =0;
        while(first<= last){
            int mid = first + (last - first)/2;
            int val = getSmaller(matrix , mid);
          
            if(val<k){
                first = mid+1;
            }else{
                last = mid-1;
                res = mid;
            }
        }return res;
    }
};