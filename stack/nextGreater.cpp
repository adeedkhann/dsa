class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);

        st.push(nums[n-1]);
        for(int i = 2*n-1 ;i >=0;i--){
           int ci = i % n;
            while(!st.empty() && st.top() <=nums[ci] ){
                st.pop();
            }


            if (i < n) {
                if (!st.empty()) {
                    res[ci] = st.top();
                }
            }
            st.push(nums[ci]);

        }return res;
    }
};