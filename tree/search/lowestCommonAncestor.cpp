/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans = NULL;
    int noLowest(TreeNode* root , TreeNode*p , TreeNode*q){
        if(root==NULL) return 0;
        int left = noLowest(root->left , p ,q);
        int right = noLowest(root->right , p , q);

        int self =0;
        if(root == p || root==q){
            self++;
        }

        int total = left +right+self;
        if(total == 2 && ans ==NULL){
            ans = root;
        }
        return total;


    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        noLowest(root , p ,q);
        return ans;
    }
};