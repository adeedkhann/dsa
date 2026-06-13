class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char , int>mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        int evencount=0;
        bool hasOdd = false;
        for(int i =0;i<mp.size();i++){
            int freq = mp[i];
            if(freq%2==0){
                evencount += freq;
            }else{
               evencount += freq-1;
               hasOdd= true;
            }  
        }
        
        if(hasOdd){
            evencount +=1;
        }
        return evencount;
    }
};