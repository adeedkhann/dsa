class Solution {
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);

        
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};