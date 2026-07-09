class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        
        vector<vector<int>>adjList(V);
        for(int i = 0;i<edges.size();i++){
            pair<int,int> p = edges[i];
            adjList[p.first].push_back(p.second);
            adjList[p.second].push_back(p.first);
        }
        return adjList;
        
    }
};