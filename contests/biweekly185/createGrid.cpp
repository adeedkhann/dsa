class Solution {
public:
    vector<string> createGrid(int m, int n) {        

        vector<string> vec(m , "");
        for(int i =0; i<m ;i++){
            string curr = "";
            if(i==0){
                for(int z = 0; z<n;z++){
                    curr += ".";
                }
            }else{
                for(int z = 0 ;z<n-1;z++){
                    curr+="#";
                }
                curr +=".";
            }

            vec[i] =curr;
        }return vec;
        
    }
};