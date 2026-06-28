class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin() , occupiedIntervals.end());
        int start1 = occupiedIntervals[0][0];
        int end1 = occupiedIntervals[0][1];
        vector<vector<int>> vp;
        for(int i = 1 ;i<occupiedIntervals.size();i++){
            int start2 = occupiedIntervals[i][0];
            int end2 = occupiedIntervals[i][1];
            if(end1>=start2 || end1 == start2-1){
                
                start1 = min(start1,start2);
                end1 = max(end1 , end2);
                
                continue;
            }else{
                vp.push_back({start1,end1});
                start1 = start2;
                end1=end2;
                continue;
                
            }
            
        }
        vp.push_back({start1 , end1});
        vector<vector<int>> pf;
        

       for (int i = 0; i < vp.size(); i++) {
            int currentStart = vp[i][0];
            int currentEnd = vp[i][1];
            if (currentStart < freeStart) {
                int validEnd = min(currentEnd, freeStart - 1);
                if (currentStart <= validEnd) {
                    pf.push_back({currentStart, validEnd});
                }
            }
            if (currentEnd > freeEnd) {
                int validStart = max(currentStart, freeEnd + 1);
                if (validStart <= currentEnd) {
                    pf.push_back({validStart, currentEnd});
                }
            }
        }
        
        return pf;
     }

    };


    //second part should be focused