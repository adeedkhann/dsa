class Solution {
public:
    bool checkPalindrome(string& s, int low, int high) {
        if (low >= high) {
            return true;
        }
        if (s[low] != s[high]) {
            return false;
        }
        return checkPalindrome(s, low + 1, high - 1);
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        return checkPalindrome(s, 0, n - 1);
    }
};