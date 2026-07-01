class Solution {

    void generator(int n,int open , int close , string &temp, vector<string>&vp){
        if(open==n && close==n){
            vp.push_back(temp);
            return ;
        }

        if(open<n){
            temp.push_back('(');
            generator(n , open+1,close , temp , vp);
            temp.pop_back();
        }

        if(close<open){
            temp.push_back(')');
            generator(n , open ,close+1 , temp , vp);
            temp.pop_back();
        }
        
        return ;

    }


public:
    vector<string> generateParenthesis(int n) {
            vector<string>vp;
            string temp ="";
            generator(n , 0 ,0 ,temp , vp );
            return vp;
    }
};