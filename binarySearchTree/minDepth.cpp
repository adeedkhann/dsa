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
 *
 * 
 * */ 

 //this is dfs but for this bfs will be more optimized
class Solution {
    int mdis=INT_MAX;
    void getdis(TreeNode*root , int dis , int &mdis){
        if(root == NULL) return ;
        if(root->left == NULL && root->right ==NULL){
            mdis = min(dis , mdis);
            return;
        }
        getdis(root->left , dis+1 , mdis);
        getdis(root->right , dis+1 , mdis);
        return ;
    }
   
public:
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
       if(root->left ==NULL && root->right ==NULL){
        return 1;
       }
       int dis = 1;
       getdis(root , dis , mdis);
       return mdis;
    }
};

//bfs

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
    int minDepth(TreeNode* root) {
       if(root == NULL) return 0;
       if(root->left ==NULL && root->right ==NULL){
        return 1;
       }
       queue<TreeNode*>q ;
       q.push(root);
       int dis = 0;
       while(!q.empty()){
        int n = q.size();
        dis++;
        while(n--){
            TreeNode* head = q.front();
            q.pop();
            if(head->left==NULL && head->right==NULL) return dis;
            if(head->left) q.push(head->left);
            if(head->right) q.push(head->right);
        }
        
       }return dis;
    }
};