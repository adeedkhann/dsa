class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int one = 0;
        int two =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }else if(nums[i]==1){
                one++;
            }else{
                two++;
            }
        }

        int i=0;
        while(zeros--){
            nums[i]=0;
            i++;
        }
        while(one--){
            nums[i]=1;
            i++;
        }
        while(two--){
            nums[i]=2;
            i++;
        }


    }
};

// soln two optimal using 3 pointers

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int med=0;
        int high=nums.size()-1;
        while(med<= high){
            if(nums[med]==0){
                swap(nums[med] , nums[low]);
                med++;
                low++;
            }
            else if(nums[med]==1){
                med++;
            }else{
                swap(nums[med] , nums[high]);
                high--;
            }
        }
    }
};a