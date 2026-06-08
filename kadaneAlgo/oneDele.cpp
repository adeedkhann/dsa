class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int nodelete = arr[0];
        int onedelete = arr[0]; 
        int max_sum = arr[0];

        for(int i = 1; i < n; i++) {
            onedelete = max(nodelete, onedelete + arr[i]);
            nodelete = max(nodelete + arr[i], arr[i]);
            max_sum = max({max_sum, nodelete, onedelete});
        }
        
        return max_sum;
    }
};