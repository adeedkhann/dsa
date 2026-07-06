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

    void getLeft(TreeNode* root, stack<TreeNode*>&smaller){
        if(smaller.empty()) return ;
        TreeNode * p = smaller.top();
        smaller.pop();
        TreeNode * rightChild = p->right;
        while(rightChild){
            smaller.push(rightChild);
            rightChild = rightChild ->left;
        }
        
    }

    void getRight(TreeNode * root , stack<TreeNode*>&bigger){
        if(bigger.empty()) return ;

        TreeNode * q = bigger.top();
        bigger.pop();
        TreeNode * leftChild = q->left;
        while(leftChild){
            bigger.push(leftChild);
            leftChild = leftChild->right;
        }
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(root->left == NULL && root->right == NULL )  return false;

        stack<TreeNode*>smaller ;
        stack<TreeNode*> bigger ;
        TreeNode* t = root;
        while(t){
            smaller.push(t);
            t=t->left;
        }
        t = root;
        while(t){
            bigger.push(t);
            t = t->right;
        }
        while(!smaller.empty() && !  bigger.empty()){
        if(smaller.top()==bigger.top()) break;
        int left = smaller.top()->val;
        int right = bigger.top()->val;
        if(left+right == k){
            return true;
        }else if(left+right < k){   
            getLeft(smaller.top() , smaller);
        }else{
            getRight(bigger.top() , bigger);
        }
        }return false;
    }
};