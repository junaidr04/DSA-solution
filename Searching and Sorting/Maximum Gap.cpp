class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        vector<int> ans;
        int Max = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            ans.push_back(nums[i + 1] - nums[i]);
            Max = max(ans[i], Max);
        }
        return Max;
    }
};