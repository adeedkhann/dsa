class Solution {
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        
        if (n < k) return -1;
        
        int maxLength = -1;
        int left = 0;
        
        unordered_map<char, int> charMap;
        
        for (int right = 0; right < n; right++) {
            charMap[s[right]]++;
            while (charMap.size() > k) {
                charMap[s[left]]--;
                
                if (charMap[s[left]] == 0) {
                    charMap.erase(s[left]);
                }
                left++;
            }
            
            if (charMap.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        return maxLength;
    }
};