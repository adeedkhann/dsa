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
    TreeNode* prev = NULL;
    TreeNode* first =NULL;
    TreeNode* second = NULL;
    void sortTree(TreeNode *root){
        if(root == NULL) return ;
        sortTree(root->left);
        if(prev != NULL && root->val < prev->val){
            if(!first){
                first = prev;
                 second = root;
            }else{
                second = root;
            }
        }
        prev = root;
        sortTree(root->right);
        
        
    }
public:
    void recoverTree(TreeNode* root) {
        sortTree(root);
        if(first && second) swap(first->val , second->val);
    }
};

// must revisit this again