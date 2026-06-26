class Solution {

    struct cmp{
        bool operator()(pair<int , string>&a , pair<int , string>&b){
            if(a.first == b.first ){
                return a.second<b.second;
            }return a.first > b.first;
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string , int> mp;
        vector<string>vp;
        for(int i = 0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int , string> , vector<pair<int,string>> ,cmp>pq;
        for(auto const& [str , freq] : mp){
            pq.push({freq , str});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            vp.push_back({pq.top().second});
            pq.pop();
        }
        reverse(vp.begin() , vp.end());
        return vp;

    }
};