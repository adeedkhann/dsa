class Solution {
    void generator(int indx, int n, vector<int>& nums, vector<vector<int>>& res) {
        if (indx == n) {
            res.push_back(nums);
            return;
        }

        for (int i = indx; i < n; i++) {
            swap(nums[indx], nums[i]);
            generator(indx + 1, n, nums, res);
            swap(nums[indx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        generator(0, n, nums, res);
        return res;
    }
};