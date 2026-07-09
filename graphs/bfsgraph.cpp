class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>res;
        vector<bool> vis(adj.size() , 0);
        queue<int> q ;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0; i<adj[node].size();i++){
                int newnode = adj[node][i];
                if(vis[newnode]==false){
                    q.push(newnode);
                    vis[newnode]= true;
                }
            }
        }
        return res;
    }
};