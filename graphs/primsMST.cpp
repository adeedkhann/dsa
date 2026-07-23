class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int , int>>> adj(V) ;
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int des = edges[i][1];
            int wt = edges[i][2];
            adj[src].push_back({des , wt});
            adj[des].push_back({src , wt});
        }
        
        vector<int>vis(V , 0);
        int ans = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int wt = p.first;
            int src = p.second;
            if(vis[src]==1) continue;
            vis[src] = 1;
            ans += wt;
            for(int i = 0;i<adj[src].size();i++){
                int neigh = adj[src][i].first;
                int newwt = adj[src][i].second;
                if(vis[neigh]==1) continue;
                                
                pq.push({newwt ,neigh});
            }
            
        }return ans;
        
        
    }
};class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int , int>>> adj(V) ;
        for(int i=0;i<edges.size();i++){
            int src = edges[i][0];
            int des = edges[i][1];
            int wt = edges[i][2];
            adj[src].push_back({des , wt});
            adj[des].push_back({src , wt});
        }
        
        vector<int>vis(V , 0);
        int ans = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int wt = p.first;
            int src = p.second;
            if(vis[src]==1) continue;
            vis[src] = 1;
            ans += wt;
            for(int i = 0;i<adj[src].size();i++){
                int neigh = adj[src][i].first;
                int newwt = adj[src][i].second;
                if(vis[neigh]==1) continue;
                                
                pq.push({newwt ,neigh});
            }
            
        }return ans;
        
        
    }
};