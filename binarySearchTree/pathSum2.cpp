/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum = 0;
    void addAns(vector<vector<int>>&ans , vector<int>&temp , TreeNode*root , int target){
        if(root == NULL) return ;
        sum += root->val;
        temp.push_back(root->val);
        if(sum == target && root->left== NULL && root->right==NULL){
            ans.push_back(temp);
        }
        addAns(ans , temp , root->left , target);
        addAns(ans , temp , root->right , target);
        temp.pop_back();
        sum -= root->val;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>temp;
        addAns(ans , temp , root , targetSum);
        return ans;
    }
};