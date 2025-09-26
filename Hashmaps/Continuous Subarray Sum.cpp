class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            int rem;
            if (k == 0)
            {
                rem = prefix;
            }
            else
            {
                rem = prefix % k;
            }
            if (mp.find(rem) != mp.end())
            {
                if (i - mp[rem] >= 2)
                {
                    return true;
                }
            }
            else
            {
                mp[rem] = i;
            }
        }
        return false;
    }
};