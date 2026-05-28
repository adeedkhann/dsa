#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int j = nums.size()-1;
        int i=0;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == target){
                return {i,j};
            }else if(sum> target){
                j--;
            }else{
                i++;
            }
        }return {};
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0; // 1. Reads the array size (5) from your input.txt
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];        // 2. Reads the 5 array elements from your input.txt
    }
    
    int target;
    cin >> target;             // 3. Reads the target value (5) from your input.txt
    
    // 4. Instantiates your class and calls the function
    Solution solver;
    vector<int> result = solver.twoSum(nums, target);
    
    // 5. Outputs the final answer (this writes directly to your output.txt)
    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}