class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,h=0;
        int res=0;
        unordered_map <char , int > hm ;
        for(h=0;h<s.size();h++){
            hm[s[h]]++;
            int k = h-l+1;
            while(hm.size() < k){
                hm[s[l]]--;
                if(hm[s[l]] == 0){
                    hm.erase(s[l]);
                }
                l++;
                k=h-l+1;
            }

            int len = h-l+1;
            res = max(res,len);
        }return res;
    }
};