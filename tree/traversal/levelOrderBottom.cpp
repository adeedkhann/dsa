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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        deque<vector<int>> dq;
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int>temp;
            while(k--){
                TreeNode * t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }dq.push_front(temp);
        }
        return vector<vector<int>>(dq.begin() , dq.end());
    }
};



// dequeu me front se add karne ki O(1) hoti hai 
// agar vector bana kar reverse karege to zyada ayega , same with insert at begin