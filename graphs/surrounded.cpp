class Solution {
    bool boundrywala(int rows , int cols , int i , int j){
        if(i==0 || j==0 || i==rows-1 || cols-1 == j) return true;
        return false;
    }
    bool isValid(int rows , int cols , int i , int j ,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=rows || j>= cols || board[i][j]=='S' || board[i][j] == 'X') return false;
        return true;
    }
    int x[4] = {0,0,1,-1};
    int y[4] = { 1,-1,0,0};
    void turno( int i , int j ,vector<vector<char>>& board ){
        board[i][j] = 'S';
        for(int k =0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(isValid(board.size() , board[0].size() , row , col , board)){
                turno(row , col , board);
            }
        }
        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if (rows <= 2 || cols <= 2) return;
        for(int i =0 ;i<rows; i+=rows-1){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O'){
                    turno(i , j , board);
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j+=cols-1){
                if(board[i][j] == 'O'){
                    turno(i , j , board);
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='S') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};