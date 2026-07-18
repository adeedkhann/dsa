class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char,int>mp;
        string t;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        if(mp[x]==0){
            return s;
        }

        int h = mp[y];
        for(int i = 0;i<h;i++){
            t.push_back(y);
            mp[y]--;
        }

        mp.erase(y);

        for(auto const&[key , val] : mp){
            for(int i=0;i<val;i++){
                t.push_back(key);
            }
        }
        return t;
    }
};