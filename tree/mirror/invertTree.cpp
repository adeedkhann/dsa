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
    void reverseTree(TreeNode* root){

        if(root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp ;
        reverseTree(root->left);
        reverseTree(root->right);
        return ;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head = root;
        reverseTree(root);
        return head;
    }
};