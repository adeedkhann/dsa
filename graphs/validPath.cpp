class Solution {

    void dfs(vector<vector<int>>&adj , int source , int dest , bool&res , vector<int>&vis){

        if(res) return;
        if(source==dest){
          res = true;
          return;  
        }  
        vis[source] =1;
        

        for(int i=0;i<adj[source].size();i++){
            int neigh = adj[source][i];
            if(vis[neigh]==0) dfs(adj , neigh , dest , res , vis);
        }
        return;
    }


public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }

        bool res = false;

        dfs(adj , source , destination , res ,vis);
        return res;


    }
};