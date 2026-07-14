class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int> free;
        unordered_map<char , int >freq;
        for(int i = 0;i<tasks.size();i++){
            free[tasks[i]] = 1;
            freq[tasks[i]]++;
        }

        priority_queue<pair<int , char>> pq;
        for(auto i : freq){
            pq.push({i.second , i.first});
        }
        int seat = 1;
        while(!pq.empty()){
            vector<pair<int , char>> vp;
            while(!pq.empty()){
                pair<int , char> p= pq.top();
                pq.pop();
                if(free[p.second] <= seat ){
                    free[p.second ] = seat+n+1;
                    p.first--;
                    if(p.first>0) pq.push({p.first , p.second});
                    break;
                }else{
                    vp.push_back(p);
                }
            }
            for(int i =0;i<vp.size();i++){
                pq.push(vp[i]);
            }
            seat++;
            vp.clear();
        }

        return seat-1;


    }
};

// not good approach only beats 5 percent in t and m 