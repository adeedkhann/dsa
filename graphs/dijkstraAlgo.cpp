// revisit


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<int>ans(V,INT_MAX);
        
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0;i<edges.size();i++){
            int first = edges[i][0];
            int second = edges[i][1];
            int third = edges[i][2];
            adj[first].push_back({ third ,second});
            adj[second].push_back({ third ,first});
        }
        priority_queue<pair<int ,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        ans[src] = 0;
        pq.push({0 ,src});
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            if (p.first > ans[p.second]) continue;
            for(int i = 0 ;i<adj[p.second].size();i++){
                int neigh = adj[p.second][i].second;
                int ndis = adj[p.second][i].first;
                if(ndis + p.first < ans[neigh]){
                    ans[neigh] = ndis + p.first;
                    pq.push({ndis+p.first , neigh});
                }
                
            }
        }return ans;
        
    }
};