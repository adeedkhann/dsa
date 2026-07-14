class Solution {

    void dfs(vector<vector<int>>&graph , vector<int>&colors , int node , int color , bool &bipartite ,int parent){

        if(bipartite == false) return ;
        for(int i = 0;i<graph[node].size();i++){
            int neigh = graph[node][i];

            if(neigh == parent){
                continue;
            }

            if(colors[neigh] == color ){
                bipartite = false;
            }else if(colors[neigh] == 0){
                if(color == 1){
                    colors[neigh] = 2;
                    dfs(graph , colors , neigh , 2 , bipartite , node);
                }else{
                    colors[neigh] = 1;
                    dfs(graph , colors , neigh  ,1 , bipartite , node);
                }
            }
        }

        return;
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size() ,0);
        bool bipartite = true;
        for(int i=0;i<graph.size();i++){
            if(colors[i] == 0){
                dfs(graph , colors , i , 1 , bipartite ,-1);
            }
        }
        return bipartite;
    }
};