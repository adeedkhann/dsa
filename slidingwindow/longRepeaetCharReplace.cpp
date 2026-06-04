class Solution {
public:

    int FindMax(int nums[]){
            int max =INT_MIN;

            for(int i=0 ; i<256;i++){
                if(nums[i]>max){
                    max=nums[i];
                }
            }return max;
        }

    int characterReplacement(string s, int k) {
        int arr[256];

        int l=0,h=0,res=INT_MIN;

        

        int len = 0;
        for(h=0;h<s.size();h++){
            arr[s[h]]++;
            len = h-l+1;
            int maxm = FindMax(arr);
            int dif = len-maxm;
            while(dif > k){
                arr[s[l]]--;
                l++;
                len = h-l+1;
                maxm = FindMax(arr);
                 dif = len-maxm;
            }
            len=h-l+1;
            res = max(res,len);

        }
            return res;

    }
};