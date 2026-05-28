#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       int i =0;
       int j =nums.size()-1;
       vector<int>arr;
       while(i<=j){
        int first=nums[i]*nums[i];
        int second=nums[j]*nums[j];
        if(first<second){
            arr.push_back(second);
            j--;
        }else{
            arr.push_back(first);
            i++;
        }
            
       }
      reverse(arr.begin(),arr.end());
       
       return arr;
       
    }
};