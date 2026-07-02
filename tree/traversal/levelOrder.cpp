/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

    if (root == NULL) {
        return {};
    }
      vector<vector<int>>vp;
      queue<TreeNode*>q ;
      q.push(root);
      while(!q.empty()){
            int k  = q.size();
            vector<int>temp;
            while(k--){
                TreeNode* t = q.front();
                temp.push_back(t->val);
                q.pop();
                if(t->left != NULL){
                    q.push(t->left);
                }
                if(t->right != NULL){
                    q.push(t->right);
                }
            }vp.push_back(temp);
        
        }return vp;

      };
};
