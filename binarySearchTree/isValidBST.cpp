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

    bool isValid(TreeNode*root , long maxm , long minm){
        if(root==NULL) return true;

        if(root->val >= maxm || root->val <= minm){
            return false;
        }
        bool forleft = isValid(root->left ,root->val ,minm );
        bool forright = isValid(root->right , maxm, root->val);

        return forleft && forright;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return isValid(root , LONG_MAX , LONG_MIN);
        

    }
};