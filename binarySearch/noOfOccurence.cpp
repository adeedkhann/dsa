class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        auto range = equal_range(arr.begin(), arr.end(), target);
        return distance(range.first, range.second);
    }
};
