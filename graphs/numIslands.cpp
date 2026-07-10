// visited array dfs approach
class Solution {
    bool isValid(int row , int col , int n , int m){
        if(row<0 || col <0 || row>= n || col >= m) return false;
        return true;
    }

    int x[4] = {0 ,0,1,-1};
    int y[4] = {-1 , 1 ,0 ,0};

    void dfs(vector<vector<char>> &grid , int i , int j , vector<vector<bool>>& vis ){
        
        vis[i][j] = 1;
        for(int k = 0;k<4;k++){
            int row = i + x[k];
            int col  = j+ y[k];
            if(isValid(row, col, grid.size(), grid[0].size()) && grid[row][col] == '1' && !vis[row][col]){
            dfs(grid , row , col , vis);
        }
        }


        return ;

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n);
        for(int i = 0 ;i<n ;i++){
            vector<bool> t (m,0);
            vis[i] = t;
        }

        for(int i = 0 ; i<n; i++){
            for(int j=0;j<m ; j++){
                if(grid[i][j]=='1' && vis[i][j]==0  ){
                    dfs(grid , i , j , vis );
                    res++;
                }
            }
        }return res;
    }
};


//sinkig island approach dfs
class Solution {
    bool isValid(int row , int col , int n , int m){
        if(row<0 || col <0 || row>= n || col >= m) return false;
        return true;
    }

    int x[4] = {0 ,0,1,-1};
    int y[4] = {-1 , 1 ,0 ,0};

    void dfs(vector<vector<char>> &grid , int i , int j  ){
        
        grid[i][j] = 0;
        for(int k = 0;k<4;k++){
            int row = i + x[k];
            int col  = j+ y[k];
            if(isValid(row, col, grid.size(), grid[0].size()) && grid[row][col] == '1'){
            dfs(grid , row , col);
        }
        }


        return ;

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i<n; i++){
            for(int j=0;j<m ; j++){
                if(grid[i][j]=='1'  ){ 
                    dfs(grid , i , j );
                    res++;
                }
            }
        }return res;
    }
};