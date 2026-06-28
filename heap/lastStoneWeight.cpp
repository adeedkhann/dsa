class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i : stones){
            pq.push(i);
        }

        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            if(x == y){
                pq.pop();
            }else{
                y = y-x;
                pq.pop();
                pq.push(y);

            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};