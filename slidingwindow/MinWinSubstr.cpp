class Solution {
public:

    bool sahiHai(vector<int>&have , vector<int>&needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false ;
            }
        }return true;
    }


    string minWindow(string s, string t) {
       vector<int> needed(256,0);
        vector<int> have(256,0);
        int res = INT_MAX;
         int start=0;
        for(int i = 0; i < t.size(); i++) {
    needed[t[i]]++;
}

        int low=0,high=0;
        for(high=0;high<s.size();high++){
            have[s[high]]++;
            while(sahiHai(have  , needed)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }return res == INT_MAX ? "" : s.substr(start, res);
}
};