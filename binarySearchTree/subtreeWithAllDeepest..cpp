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
    pair<TreeNode* , int> getLca(TreeNode*root , int d){
    if(root ==NULL ) return {root , d};
    pair<TreeNode* , int> left = getLca(root->left , d+1);
    pair<TreeNode* , int> right = getLca(root->right , d+1);
    if(left.second>right.second){
        return left;
    }else if(right.second>left.second){
        return right;
    }else{
       return {root, left.second};
    }
   }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return NULL;
        pair<TreeNode* , int> p = getLca(root , 0);
        return p.first;
    }
};