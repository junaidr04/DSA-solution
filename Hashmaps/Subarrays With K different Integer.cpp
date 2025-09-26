class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++)
        {
            freq[nums[right]]++;
            while (freq.size() > k)
            {
                freq[nums[left]]--;
                {
                    if (freq[nums[left]] == 0)
                    {
                        freq.erase(nums[left]);
                    }
                    left++;
                }
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};