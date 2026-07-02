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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        bool turn = true;
        vector<vector<int>>res ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k= q.size();
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
                
            }
           
            if(!turn){
                reverse(temp.begin() , temp.end());
            }
            res.push_back(temp);
            turn = !turn;
        }return res;
    }
};