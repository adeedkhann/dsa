class Solution {
    
    
    void dfs(vector<vector<int>> &adj , vector<int>&res , vector<bool>&vis , int node){
        res.push_back(node);
        vis[node] = true;
        
        for(int i = 0;i<adj[node].size();i++){
            int negh = adj[node][i];
            if(vis[negh]==false){
                dfs(adj , res , vis , negh);
            }
        }
        return ;
        
    }
        
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<int> res;
        vector<bool>vis(adj.size() , 0);
        dfs(adj , res , vis , 0);
        return res;
    
    }
};