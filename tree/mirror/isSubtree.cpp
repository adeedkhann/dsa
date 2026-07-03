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

    bool isTree(TreeNode*root , TreeNode*subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        if(root->val != subRoot->val) return false;
        
        bool r1 = isTree(root->left , subRoot->left);
        bool r2 = isTree(root->right , subRoot->right);
        
        return r1 && r2;
    }



public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;


       if(isTree(root , subRoot)==true){
        return true;
       }
       bool r1 = isSubtree(root->left , subRoot);
       bool r2 = isSubtree(root->right , subRoot);
       return r1 || r2;

    }
};