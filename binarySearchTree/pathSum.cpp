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
    bool mila = false;
    void getSum(TreeNode*root , int target){
        if(root==NULL) return;
        sum += root->val;
        if(sum == target && root->left == NULL && root->right == NULL){
            mila = true;
        }

        getSum(root->left , target);
        getSum(root->right , target);
        sum -= root->val;
        return;
    }

public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        getSum(root , targetSum);
        return mila;
    }
};