class Solution {
    
    
    string recursion(string &s , int i , int n , char c){
        if(i==n){
            return "";
        }
        string ans = recursion(s , i+1,n ,c);
        if(s[i] == c){
            return ans;
        }
        return s[i]+ ans;
        
    }
    
    
    
  public:
    void removeCharacter(string &s, char c) {
    s = recursion(s , 0, s.size() , c);
    }
};


// in place approach for optimisation.
class Solution {
    void solve(string &s, int i, int &j, char c) {
        if (i == s.size()) {
            s.resize(j);
            return;
        }
        
        if (s[i] != c) {
            s[j] = s[i]; 
            j++;
        }
        
        solve(s, i + 1, j, c);
    }
    
public:
    void removeCharacter(string &s, char c) {
        int writeIndex = 0;
        solve(s, 0, writeIndex, c);
    }
};