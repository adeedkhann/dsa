class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size() - 1;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;
            
            if (nums[low] <= nums[mid]) { // Left half sorted hai
            if (nums[low] <= target && target < nums[mid]) high = mid - 1; // Target left range mein hai
            else low = mid + 1;
            } else { // Right half sorted hai
                    if (nums[mid] < target && target <= nums[high]) low = mid + 1; // Target right range mein hai
                    else high = mid - 1;
                    }
        }
        return -1;
    }
};