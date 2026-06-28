class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int , int>> vp;
        for(int i =0;i<profits.size();i++){
            vp.push_back({capital[i] ,profits[i]});
        }
        sort(vp.begin() , vp.end());
        priority_queue<int> pq;
        int idx = 0;
        while(k--){
            while(idx < n && vp[idx].first <= w){
                if(vp[idx].first>w){
                    break;
                }
                pq.push(vp[idx].second);
                idx++;
            }
            if(pq.empty()){
                return w;
            }
            w=w+pq.top();
            pq.pop();
        }return w;
    }
};