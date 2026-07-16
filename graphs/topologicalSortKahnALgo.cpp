class Solution {
        
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>indegree(V,0);
        vector<vector<int>>adj(V);
        vector<int>ans;
        for(int i =0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            indegree[second]++;
        }
        
        queue<int>q;
        
        for(int i = 0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i];
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }return ans;
    }
};