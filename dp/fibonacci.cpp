class Solution {
public:
    int fib(long long n) {

        // this soln using O(1) space dp ; (wow)
        // if(n<1) return n;
        // int prev = 1;
        // int prev2 = 0;
        // for(int i = 2 ;i<=n;i++){
        //     int curi = prev +prev2;
        //     prev2 = prev;
        //     prev = curi;
        // }return prev;


        // memoization with vector
        // vector<int>dp(n+1,-1);
        // if(n<=1){
        //     return n;
        //     dp[n] = n;
        // }

        // if(dp[n]!=-1) return dp[n];
        // int res = fib(n-1) + fib(n-2);
        // return res;
        // dp[n] =res;

        // vector<int>dp(n+1 ,-1);
        // dp[0]=0;
        // dp[1]=1;
        // for(int i = 2;i<= n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }return dp[n];

    }
};