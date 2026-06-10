class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        int zero = 0;
        int res = 0;
        unordered_map<int,int>hm;
        for(int i =0;i<nums.size();i++){
           
        if(nums[i]==0){
            zero++;
        }else{
            one++;
        }

        int dif = one - zero;

        if(dif==0){
            res = max(res , i+1);
        }
        
        if(hm.find(dif) == hm.end()){
            hm[dif] = i;
        }else{
            int idx = hm[dif];
            int len = i - idx;
            res = max(len , res);
        }


        }return res;
    }
};