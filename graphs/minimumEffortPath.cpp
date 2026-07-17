class Solution {

    struct Data{
        int dist , i  , j;
    };

    struct compareData{
        bool operator()(const Data&a ,const Data&b){
        return a.dist>b.dist;
        }
    };

    bool isValid(int row , int col , int n , int m){
        if(row<0 || col < 0 || row>=n || col >=m) return false;
        return true;
    };


public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};


        vector<vector<int>>answer(n , vector<int>(m, INT_MAX));

        answer[0][0]=0;
        priority_queue<Data , vector<Data> , compareData> pq;

        pq.push({0 , 0 , 0});
        while(!pq.empty()){
            auto [dist , row , col] = pq.top();
            pq.pop();
            if(dist>answer[row][col]) continue;
            for(int k=0;k<4;k++){
                int i = row+ x[k];
                int j = col + y[k];
                if(!isValid(i , j , n , m) ) continue;
                int path = abs(heights[i][j]-heights[row][col]);
                int newdis = max(path , dist);
                if(newdis<answer[i][j]){
                    answer[i][j]=newdis;
                    pq.push({newdis , i , j});
                }
                
            }
        }return answer[n-1][m-1];
    }
};