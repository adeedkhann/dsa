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
    void getTree(vector<int> &trees , TreeNode *root){
           if( root == NULL){
            return;
        };
        trees.push_back(root->val);
        getTree(trees , root->left);
        getTree(trees , root->right);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>trees;
        getTree(trees , root);
        return trees;
    }
};