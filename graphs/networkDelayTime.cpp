class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int src = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];
            adj[src].push_back({dest , weight});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int , int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        int ans =INT_MIN;

        dist[k]=0;
        pq.push({0 , k});
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            for(int i=0;i<adj[p.second].size();i++){
                int neigh = adj[p.second][i].first;
                int dis = adj[p.second][i].second;
                if(dis+p.first <dist[neigh]){
                    dist[neigh] = dis+p.first;
                    pq.push({dis+p.first , neigh});
                }
            }
        }
       
        for(int i=1;i<dist.size();i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans , dist[i]);
        }
        return ans;
    }
};