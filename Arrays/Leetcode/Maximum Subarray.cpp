class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxP = max(nums[i], maxP + nums[i]);
            ans = max(ans, maxP);
        }
        return ans;
    }
};