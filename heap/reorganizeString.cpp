class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> mp;
        for(char i : s){
            mp[i]++;
        }
        priority_queue<pair<int , char>> pq;
        for(const auto &[chara , freq] :mp){
            pq.push({freq , chara});
        }
        string res="";
        int seat = 0;
        while(!pq.empty()){
            pair<int , char> p = pq.top();
            pq.pop();
            if(res.size()==0 || res[seat-1] != p.second){
            res.push_back(p.second);
            seat++;
            p.first--;
           if(p.first>0){
             pq.push(p);
           }
            }else{

                if(pq.empty()){
                    return "";
                }
                pair<int , char> q = pq.top();
                pq.pop();
                res.push_back(q.second);
                seat++;
                q.first--;
                if(q.first>0){
                pq.push(q);
                }
                pq.push(p);

            }
        }return res;
        


    }
};