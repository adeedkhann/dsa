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

    void getTree(vector<int> &trees,TreeNode *root){
        if(root==NULL){
            return ;
        }

        getTree(trees , root->left);
        trees.push_back(root->val);
        getTree(trees ,root->right);
        return;
    }



public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> trees;
        getTree(trees ,root);
        return trees;
    }
};