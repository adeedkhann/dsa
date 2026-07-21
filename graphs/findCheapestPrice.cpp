class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int>dist(n ,1e8);
    dist[src]=0;
        for(int i = 0;i<=k;i++){
            vector<int>temp = dist;
            for(int j=0;j<flights.size();j++){
            int s = flights[j][0];
            int d = flights[j][1];
            int cost = flights[j][2];
            if(dist[s]!= 1e8 && temp[d] > dist[s] + cost ){
                    temp[d]=dist[s]+cost;
                }
            }
            dist = temp;
        }

        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};