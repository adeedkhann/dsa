class Solution {
  // ye ques dfs se nahi hota aese wale ques bfs se hote hai jisse ki redially chal sake ;
    
    
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<int>dist(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int first =edges[i][0];
            int second = edges[i][1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        
        queue<pair<int,int>>q;
        q.push({src , 0});
        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int , int> p = q.front();
                q.pop();
                for(int i = 0;i<adj[p.first].size();i++){
                    int neigh = adj[p.first][i];
                    int dis = p.second+1;
                    if(dist[neigh]==0){
                        dist[neigh] = dis;
                    q.push({neigh , dis});
                    }
                    
                    
                }
                
                
            }
        }return dist[dest] == 0 ? -1 : dist[dest];
        
    }
};
