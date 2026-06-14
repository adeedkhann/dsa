class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if(magazine.size()==0 && ransomNote.size()==0) return true;
        if(magazine.size()==0  && ransomNote.size()!=0) return false; 
        unordered_map<char , int > rmp;
        unordered_map<char,int> mmp;
        
        for(int i =0;i<ransomNote.size();i++){
            rmp[ransomNote[i]]++;
        }
        for(int i =0; i<magazine.size();i++){
            mmp[magazine[i]]++;
        }

        if(mmp.size()<rmp.size()) return false;

        for(const auto&pair :rmp){
            auto it  = mmp.find(pair.first);
            if(it == mmp.end() || it -> second < pair.second){
                return false;
            }


        }return true;
        
    }
};

// good aproach , optimal

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
       vector<int> alpha(26,0);
       for(int i = 0 ;i<magazine.size();i++){
        alpha[magazine[i] - 'a']++;
       }
       for(int i = 0 ;i<ransomNote.size();i++){
        alpha[ransomNote[i] - 'a']--;

        if(alpha[ransomNote[i] - 'a']<0){
            return false;
        }
       }return true;
        
    }
};