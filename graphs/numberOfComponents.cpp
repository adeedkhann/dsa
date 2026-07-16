// brute force is accepted but isme dsu karke lagta hai kuch




class Solution {

    int intersect(vector<int>a , vector<int>b){
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        int count =0;
        for (int i = 0; i < a.size(); i++) {
            if (i > 0 && a[i] == a[i - 1]) continue;
            for (int j = 0; j < b.size(); j++) {
                if (j > 0 && b[j] == b[j - 1]) continue;
                
                if (a[i] == b[j]) {
                    count++;
                }
            }
        }
        return count;
    }


    void dfs(const vector<vector<int>>&adj ,vector<bool>&vis , int node){
        vis[node]=true;
        for(int i =0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(!vis[neigh]) dfs(adj , vis , neigh);
        }
        return ;
    }


public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {

        vector<vector<int>>adj(properties.size());
        vector<bool>vis(properties.size() ,0);
        int ans =0;
        for(int i=0;i<properties.size();i++){
            for(int j=i+1;j<properties.size();j++){
                if(intersect(properties[i] , properties[j]) >= k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i =0;i<vis.size();i++){
            if(!vis[i]){
                dfs(adj , vis , i);
                ans++;
            }
        }
        return ans;

    }
};