class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        for(int i = 0;i<points.size();i++){
            for(int j = 0;j<points.size();j++){
                if(i==j) continue;
                int dist = abs( abs(points[i][0] - points[j][0]) + abs( points[i][1]  - points[j][1]));
                adj[i].push_back({dist , j});
            }
        }

        vector<int> vis(points.size() , 0);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0 , 0});
        int ans = 0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            int dist = p.first;
            int src = p.second;
            if(vis[src]  == 1) continue;
            vis[src]= 1;
            ans += dist ;
            for(int i = 0 ;i<adj[src].size();i++){
                int neigh = adj[src][i].second;
                int newt = adj[src][i].first;
                if(vis[neigh]==1) continue;
                pq.push({newt , neigh});
            }
        }return ans;



    }
};