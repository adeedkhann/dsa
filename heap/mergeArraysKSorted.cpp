class Solution {
        
    struct Element{
        int value;
        int row;
        int col;
    };
    
    struct cmp {
        bool operator()(const Element&A , const Element&B){
            return A.value>B.value;
        }
    };
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> res;
        priority_queue<Element , vector<Element> , cmp> pq;
        
        for(int i = 0;i<mat.size();i++){
            pq.push({mat[i][0] , i , 0});
        }  
        
        while(!pq.empty()){
            int value = pq.top().value;
            int row = pq.top().row;
            int col = pq.top().col;
            pq.pop();
            res.push_back(value);
            if(col+1 < mat[row].size()){
                pq.push({mat[row][col+1] , row , col+1});
            }
            
        }
    
        return res;
    }
};