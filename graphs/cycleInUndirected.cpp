class Solution {
    
    bool searchcycle(vector<vector<int>>&adj , vector<bool>&vis , int parent , int node , bool &cycle){
        if(cycle==true) return true;
        vis[node] = 1;
        for(int j =0;j<adj[node].size();j++){
            int neigh = adj[node][j];
            if(vis[neigh] == 1 && parent!=neigh){
                cycle = 1;
            }else if(vis[neigh] == 0){
                searchcycle(adj , vis , node , neigh , cycle);
            }
        }
        return false;
    }
    
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
       
     vector<vector<int>> adj (V);
     for(int i = 0;i<edges.size() ;i++){
         int first = edges[i][0];
         int second = edges[i][1];
         
        adj[first].push_back(second);
        adj[second].push_back(first);
     }
     
     vector<bool> vis(V,0);
     bool cycle = false;
     for(int i = 0;i<vis.size();i++){
         if(vis[i]==0){
             searchcycle(adj , vis , -1 , i , cycle);
         }
     }
     return cycle;
     
     
    }
};