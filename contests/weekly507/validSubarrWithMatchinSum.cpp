class Solution {

    bool isCorrect(long long sum , int x){
        int last = sum%10;
        while(sum>=10){
            sum=sum/10;
        }
        int first = sum;
        return (first == x && last == x);
    }

public:
    int countValidSubarrays(vector<int>& nums, int x) {
        long long ans = 0;
        long long sum = 0;
        for(int i=0; i<nums.size();i++){
            sum =0;
            for(int j=i;j<nums.size();j++){
            sum+=nums[j];
               bool cor = isCorrect(sum , x);
               if(cor){
                ans++;
               }
            }
        }return ans;
    }
};