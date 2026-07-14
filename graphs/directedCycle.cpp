
class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& state, int node) {
        state[node] = 1;
        for (int neigh : adj[node]) {
            if (state[neigh] == 1) {
                return true;
            }
            if (state[neigh] == 0) {
                if (dfs(adj, state, neigh)) {
                    return true;
                }
            }
        }
        
        state[node] = 2;
        return false;
    }
    
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> state(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (state[i] == 0) {
                if (dfs(adj, state, i)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};