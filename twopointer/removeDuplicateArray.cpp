class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0) return 0;
        int i = 0;
        int count = 1;
        int j = 1;

        for (int k = 0; k <= nums.size() - 1; k++)
        {
            if (j == nums.size())
                return count;
            if (nums[i] == nums[j])
                j++;
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
                count++;
            }
        }
        return count;
    }
};
// isme khargosh aur kahucwe wala laga hai , hair or rabbit or slow or fast pointer