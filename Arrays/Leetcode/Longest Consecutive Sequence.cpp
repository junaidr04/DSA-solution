class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int cur = 1;
        int larg = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                cur++;
                larg = max(larg, cur);
            }
            else
            {
                cur = 1;
            }
        }
        return larg;
    }
};