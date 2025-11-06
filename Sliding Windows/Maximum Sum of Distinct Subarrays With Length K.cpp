class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        long long maxSum = 0, windowSum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            freq[nums[r]]++;
            windowSum += nums[r];
            if (r - l + 1 > k)
            {
                freq[nums[l]]--;
                windowSum -= nums[l];
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }
            if (r - l + 1 == k && freq.size() == k)
            {
                maxSum = max(maxSum, windowSum);
            }
        }
        return maxSum;
    }
};