class Solution {

    void generator(vector<int> &temp , vector<vector<int>>&res ,int indx, int n , vector<int>&candidates ,int sum , int target){

        if(sum == target){
            res.push_back(temp);
            return ;
        };

        if(sum > target){
            return ;
            
        }
        for(int i = indx; i<n;i++){
            
            temp.push_back(candidates[i]);
            sum = sum + candidates[i];
            generator(temp , res,i , n ,candidates , sum ,target);
            sum = sum - candidates[i];
            temp.pop_back();
        }
        return ;

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>>res ;
        int n =candidates.size();
        int sum = 0;
        generator(temp , res ,0, n ,candidates , sum ,target);
        return res;
    }
};


//without for loop 
class Solution {
    void generator(int indx, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (indx == candidates.size() || target < 0) {
            return;
        }

        if (candidates[indx] <= target) {
            temp.push_back(candidates[indx]);
            generator(indx, target - candidates[indx], candidates, temp, res); 
            temp.pop_back();
        }
        generator(indx + 1, target, candidates, temp, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        generator(0, target, candidates, temp, res);
        return res;
    }
};