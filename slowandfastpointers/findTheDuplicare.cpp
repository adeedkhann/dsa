class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0;
        int fast =0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];//do baar bhagao
            if(fast==slow){
                slow=0;
                while(fast!=slow){
                    slow=nums[slow];
                    fast = nums[fast];// ek ek karke bhagao
                }return slow;
            }



        }return nums[slow];


    
    }

};


