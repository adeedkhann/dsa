class Solution {
unordered_map < char , string > mp = {
            {'2' ,"abc"},
           {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
    void generator(string &digits ,string &temp ,int num ,int idx ,vector<string> &vp){
        
        if(idx==num){
            vp.push_back(temp);
            return;
        }
        string letters = mp[digits[idx]];
        for(int i =0;i<letters.size();i++){
        temp.push_back(letters[i]);
        generator(digits , temp , num , idx+1 ,vp);
        temp.pop_back();

        }
                return;


    }


public:
    vector<string> letterCombinations(string digits) {
        string temp ="";
        
        int num = digits.size();
        vector<int> h ;
        vector<string> vp; 
        int idx = 0;
        generator(digits ,temp ,num ,idx ,vp);
        return vp;
    }
};