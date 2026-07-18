class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return (long long)s; 
        long long ans = (long long)s + ((long long)(n/2)*m) -  n/2;
        return ans+1;
    }
};