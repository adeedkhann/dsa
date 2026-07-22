class Solution {

    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};
    bool isValid(int row , int col , int n , int m){
        if(row<0 || col<0 || row>= n || col >= m) return false;
        return true;
    }
    bool bfs(vector<vector<int>>&grid , int level){
        if(grid[0][0] > level) return false;
        vector<vector<int>> visited(
        grid.size(),
        vector<int>(grid[0].size(), 0)
        );
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int k = 0;k<4;k++){
                int row = p.first + x[k];
                int col = p.second + y[k];
                if(isValid(row , col , grid.size() ,grid[0].size()) && grid[row][col]<=level && visited[row][col]==0){
                    q.push({row , col});
                    if(row==grid.size()-1 && col == grid[0].size()-1) return true;
                    visited[row][col]=1;
                }
            }
        }return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1 ) return grid[0][0];
        int low = grid[0][0];
        int high = 0;

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                high = max(high , grid[i][j]);
            }
        }
        
        int res = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            bool yes = bfs(grid , mid);
            if(yes){
                high = mid-1;
                res = mid;
            }else{
                low = mid+1;
                
            }
        }
        return res;

    }
};