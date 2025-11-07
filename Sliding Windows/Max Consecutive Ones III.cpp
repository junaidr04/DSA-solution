class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, ans = 0, onesCount = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 1)
                onesCount++;
            while ((r - l + 1) - onesCount > k)
            {
                if (nums[l] == 1)
                    onesCount--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
